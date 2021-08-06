/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:04:18 by akliek            #+#    #+#             */
/*   Updated: 2021/08/06 15:22:26 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_data	zoom_init(t_data data)
{
	data.zoom.x_max_zoom = 0;
	data.zoom.x_min_zoom = 0;
	data.zoom.y_max_zoom = 0;
	data.zoom.y_min_zoom = 0;
	return (data);
}

int	zoom(int key, t_data data)
{
	// mlx_destroy_image(data.mlx.mlx, data.mlx.img);
	if (key == 126)
	{
		data.zoom.x_max_zoom += 0.2;
		data.zoom.x_min_zoom += 0.2;
		data.zoom.y_max_zoom += 0.2;
		data.zoom.y_min_zoom += 0.2;
	}
	else if (key == 125)
	{
		data.zoom.x_max_zoom -= 0.2;
		data.zoom.x_min_zoom -= 0.2;
		data.zoom.y_max_zoom -= 0.2;
		data.zoom.y_min_zoom -= 0.2;
	}
	draw(data);
	return (0);
}
