/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:15:07 by akliek            #+#    #+#             */
/*   Updated: 2021/08/06 15:23:22 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fract_ol.h"

int	close_fractal(int key)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || ((ft_strcmp(argv[1], "Mandelbrot"))
			&& (ft_strcmp(argv[1], "Julia") || argc < 3)))
	{
		perror("Usage: ./fracol Mandelbrot || Julia");
		return (0);
	}
	if (*argv[1] == 'J')
	{
		data.julia = 1;
		data.julia_type = *argv[2];
	}
	data = zoom_init(data);
	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, 1080, 1080, "fract_ol");
	data.mlx.img = mlx_new_image(data.mlx.mlx, 1080, 1080);
	data.mlx.addr = mlx_get_data_addr(data.mlx.img, &data.mlx.bits_per_pixel,
			&data.mlx.line_length, &data.mlx.endian);
	draw(data);
	mlx_hook(data.mlx.win, 2, 0, close_fractal, &data);
//	mlx_hook(data.mlx.win, 2, 0, zoom, &data);
	mlx_loop(data.mlx.mlx);
}
