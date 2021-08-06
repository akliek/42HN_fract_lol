/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:00:10 by akliek            #+#    #+#             */
/*   Updated: 2021/08/06 14:38:53 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdbool.h>
# include <math.h>

struct	s_mlx
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
	void	*mlx;
	void	*win;
	void	*img;
};

struct s_zoom
{
	float	x_max_zoom;
	float	x_min_zoom;
	float	y_max_zoom;
	float	y_min_zoom;	
};

typedef struct s_data
{
	bool			julia;
	char			julia_type;
	float			x;
	float			y;
	float			or_x;
	float			or_y;
	float			real;
	float			imagine;
	float			x_max;
	float			y_max;
	float			x_min;
	float			y_min;
	struct s_mlx	mlx;
	struct s_zoom	zoom;
}				t_data;

t_data	zoom_init(t_data data);
int		zoom(int key, t_data data);
int		ft_strcmp(const char *s1, const char *s2);
void	draw(t_data data);
int		algorithm(t_data data);

#endif
