/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:15:07 by akliek            #+#    #+#             */
/*   Updated: 2021/08/11 12:06:56 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	error_check(int argc, char **argv)
{
	if (argc < 2 || (ft_strcmp(argv[1], "Mandelbrot")
			&& ft_strcmp(argv[1], "Burning Ship")
			&& ft_strcmp(argv[1], "Julia")))
	{
		perror("Usage: ./fractol Mandelbrot || Julia || Burning Ship");
		return (0);
	}
	if (!ft_strcmp(argv[1], "Julia") && argc < 3)
	{
		perror("Usage: ./fractol Mandelbrot || Julia || Burning Ship");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (!error_check(argc, argv))
		return (0);
	if (argc < 2)
		return (0);
	if (*argv[1] == 'J' || *argv[1] == 'B')
	{
		data.type = *argv[1];
		if (*argv[1] == 'J')
			data.julia_type = *argv[2];
	}
	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, WIDTH, HEIGHT, "fract_ol");
	data = start_init(data);
	multithread(&data);
	mlx_hook(data.mlx.win, 2, 0, keyboard_hooks, &data);
	mlx_hook(data.mlx.win, 4, 0, zoom, &data);
	mlx_loop(data.mlx.mlx);
}
