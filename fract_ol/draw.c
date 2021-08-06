/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:29:45 by akliek            #+#    #+#             */
/*   Updated: 2021/08/06 15:26:30 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(struct s_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static t_data	julia_init(char type, t_data data)
{
	if (type == '1')
	{
		data.or_x = 0.285;
		data.or_y = 0;
	}
	else if (type == '2')
	{
		data.or_x = 0.285;
		data.or_y = 0.01;
	}
	else if (type == '3')
	{
		data.or_x = 0.45;
		data.or_y = 0.1428;
	}
	else if (type == '4')
	{
		data.or_x = -0.835;
		data.or_y = -0.2321;
	}
	return (data);
}

static t_data	init_data(float w, float h, t_data data)
{
	data.x_max = 2 - data.zoom.x_max_zoom;
	data.x_min = -2 + data.zoom.x_min_zoom;
	data.y_max = 2 - data.zoom.y_max_zoom;
	data.y_min = -2 + data.zoom.y_min_zoom;
	data.x = w / (1080 / (data.x_max + fabs(data.x_min))) - fabs(data.x_min);
	data.or_x = data.x;
	data.y = h / (1080 / (data.y_max + fabs(data.y_min))) - fabs(data.y_max);
	data.or_y = data.y;
	if (data.julia == 1)
		data = julia_init(data.julia_type, data);
	return (data);
}

void	draw(t_data data)
{
	int		n;
	float	w;
	float	h;

	w = 0;
	while (w < 1080)
	{
		h = 0;
		while (h < 1080)
		{
			data = init_data(w, h, data);
			n = algorithm(data);
			if (n < 100 && n >= 10)
				my_mlx_pixel_put(&data.mlx, w, h, (n * 10) * 0x00ffff00);
			else if (n < 10)
				my_mlx_pixel_put(&data.mlx, w, h, (n * 20) % 0x00ffff00);
			else
				my_mlx_pixel_put(&data.mlx, w, h, 0x00000000);
			h++;
		}
		w++;
	}
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.mlx.img, 0, 0);
}
