/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:00:10 by akliek            #+#    #+#             */
/*   Updated: 2021/08/10 16:45:44 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define WIDTH 1080
# define HEIGHT 1080
# define ESC_KEY 53
# define PLUS_KEY 69
# define MINUS_KEY 78
# define SPACE_KEY 49
# define ARROW_UP_KEY 126
# define ARROW_DOWN_KEY 125
# define ARROW_RIGHT_KEY 124
# define ARROW_LEFT_KEY 123
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

struct	s_mlx
{
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*addr;
	void			*mlx;
	void			*win;
	void			*img;
};

typedef struct s_data
{
	int				end;
	int				start;
	int				color;
	int				iteration;
	char			type;
	char			julia_type;
	double			x;
	double			y;
	double			c_x;
	double			c_y;
	double			x_max;
	double			y_max;
	double			x_min;
	double			y_min;
	double			real;
	double			imagine;
	struct s_mlx	mlx;
}					t_data;

int		algorithm(t_data data);
int		keyboard_hooks(int key, t_data *data);
int		zoom(int key, int x, int y, t_data *data);
int		ft_strcmp(const char *s1, const char *s2);
void	*draw(void *arg);
void	multithread(t_data *data);
t_data	start_init(t_data data);
t_data	convert_to_coordinate(double w, double h, t_data data);

#endif
