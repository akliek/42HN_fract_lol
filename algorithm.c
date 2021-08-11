/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:27:40 by akliek            #+#    #+#             */
/*   Updated: 2021/08/11 12:49:29 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	algorithm(t_data data)
{
	int	n;

	n = 0;
	while (n < data.iteration)
	{
		if (data.type == 'B')
			data.imagine = -2 * fabs(data.x * data.y);
		else
			data.imagine = 2 * data.x * data.y;
		data.real = data.x * data.x - data.y * data.y;
		data.x = data.real + data.c_x;
		data.y = data.imagine + data.c_y;
		if (data.x * data.x + data.y * data.y > 4)
			break ;
		n++;
	}
	return (n);
}
