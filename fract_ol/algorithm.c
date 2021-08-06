/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:27:40 by akliek            #+#    #+#             */
/*   Updated: 2021/08/05 17:57:23 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	algorithm(t_data data)
{
	int	n;

	n = 0;
	while (n < 100)
	{
		data.imagine = 2 * data.x * data.y;
		data.real = data.x * data.x - data.y * data.y;
		data.x = data.real + data.or_x;
		data.y = data.imagine + data.or_y;
		if (data.x * data.x + data.y * data.y > 16)
			break ;
		n++;
	}
	return (n);
}
