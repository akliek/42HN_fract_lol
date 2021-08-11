/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:23:35 by akliek            #+#    #+#             */
/*   Updated: 2021/08/10 17:03:40 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	multithread(t_data *data)
{
	t_data		fractals[10];
	pthread_t	threads[10];
	int			i;

	i = 0;
	data->mlx.img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel,
			&data->mlx.line_length, &data->mlx.endian);
	while (i < 10)
	{
		fractals[i] = *data;
		fractals[i].start = i * (WIDTH / 10);
		fractals[i].end = (i + 1) * (HEIGHT / 10);
		if (pthread_create(&threads[i], NULL, draw, &fractals[i]))
			perror("Error: can't create thread\n");
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			perror("Error: can't join thread\n");
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}
