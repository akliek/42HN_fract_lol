/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:20:37 by akliek            #+#    #+#             */
/*   Updated: 2021/08/10 13:51:45 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	moving(int key, t_data *data)
{
	double	move_y;
	double	move_x;

	move_y = fabs(data->y_max - data->y_min) / 100;
	move_x = fabs(data->y_max - data->y_min) / 100;
	if (key == ARROW_UP_KEY)
	{
		data->y_max += move_y;
		data->y_min += move_y;
	}
	else if (key == ARROW_DOWN_KEY)
	{
		data->y_max -= move_y;
		data->y_min -= move_y;
	}
	else if (key == ARROW_RIGHT_KEY)
	{
		data->x_max += move_x;
		data->x_min += move_x;
	}
	else if (key == ARROW_LEFT_KEY)
	{
		data->x_max -= move_x;
		data->x_min -= move_x;
	}
}

static void	iteration(int key, t_data *data)
{
	if (key == PLUS_KEY)
		data->iteration += 10;
	else if (key == MINUS_KEY)
		data->iteration -= 10;
}

static void	color(int key, t_data *data)
{
	if (key == SPACE_KEY)
		data->color += 0x0000ff00;
}

int	keyboard_hooks(int key, t_data *data)
{
	if (key == ESC_KEY)
		exit(0);
	color(key, data);
	moving(key, data);
	iteration(key, data);
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	multithread(data);
	return (0);
}

int	zoom(int key, int x, int y, t_data *data)
{
	double		mouse_x_pos;
	double		mouse_y_pos;

	mouse_x_pos = (double)x / (WIDTH / (data->x_max - data->x_min))
		+ data->x_min;
	mouse_y_pos = (double)y / (HEIGHT / (data->y_max - data->y_min))
		* -1 + data->y_max;
	if (key == SCROLL_UP)
	{
		data->x_min = mouse_x_pos + (data->x_min - mouse_x_pos) * 0.7;
		data->x_max = mouse_x_pos + (data->x_max - mouse_x_pos) * 0.7;
		data->y_min = mouse_y_pos + (data->y_min - mouse_y_pos) * 0.7;
		data->y_max = mouse_y_pos + (data->y_max - mouse_y_pos) * 0.7;
	}
	else if (key == SCROLL_DOWN)
	{
		data->x_min = mouse_x_pos + (data->x_min - mouse_x_pos) * 1.3;
		data->x_max = mouse_x_pos + (data->x_max - mouse_x_pos) * 1.3;
		data->y_min = mouse_y_pos + (data->y_min - mouse_y_pos) * 1.3;
		data->y_max = mouse_y_pos + (data->y_max - mouse_y_pos) * 1.3;
	}
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	multithread(data);
	return (0);
}
