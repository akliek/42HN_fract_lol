/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:48:59 by akliek            #+#    #+#             */
/*   Updated: 2021/08/11 12:48:49 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static t_data	julia_init(char type, t_data data)
{
	if (type == '1')
	{
		data.c_x = 0.285;
		data.c_y = 0;
	}
	else if (type == '2')
	{
		data.c_x = 0.285;
		data.c_y = 0.01;
	}
	else if (type == '3')
	{
		data.c_x = 0.45;
		data.c_y = 0.1428;
	}
	else if (type == '4')
	{
		data.c_x = -0.835;
		data.c_y = -0.2321;
	}
	return (data);
}

t_data	start_init(t_data data)
{
	data.x_max = 2;
	data.y_max = 2;
	data.x_min = -2;
	data.y_min = -2;
	data.color = 0x00ffff00;
	data.iteration = 100;
	return (data);
}

t_data	convert_to_coordinate(double w, double h, t_data data)
{
	data.x = w / (WIDTH / (data.x_max - data.x_min)) + data.x_min;
	data.c_x = data.x;
	data.y = h / (HEIGHT / (data.y_max - data.y_min)) * -1 + data.y_max;
	data.c_y = data.y;
	if (data.type == 'J')
		data = julia_init(data.julia_type, data);
	return (data);
}
