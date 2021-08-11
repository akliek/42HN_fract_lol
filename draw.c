/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:29:45 by akliek            #+#    #+#             */
/*   Updated: 2021/08/11 12:56:35 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx.addr + (y * data->mlx.line_length
			+ x * (data->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	*draw(void *arg)
{
	int		n;
	double	w;
	double	h;
	t_data	*data;

	data = arg;
	w = data->start;
	while (w < data->end)
	{
		h = 0;
		while (h < HEIGHT)
		{
			*data = convert_to_coordinate(w, h, *data);
			n = algorithm(*data);
			if (n < data->iteration && n >= 10)
				my_mlx_pixel_put(data, w, h, (n * 10) * data->color);
			else if (n < 10)
				my_mlx_pixel_put(data, w, h, (n * 20) % data->color);
			h++;
		}
		w++;
	}
	return (NULL);
}
