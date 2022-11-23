/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:54:38 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/23 18:50:38 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include "MLX42/MLX42.h"
# define ITER 50
# define RGB_MAX 16777215

typedef struct s_complex
{
	long double	real;
	long double	imaginary;
}	t_complex;

typedef struct s_vector
{
	long double	x;
	long double	y;
}	t_vector;

typedef struct s_monitor_size
{
	int32_t	x;
	int32_t	y;
}	t_monitor_size;

typedef struct s_fractal
{
	t_vector	top_left;
	t_vector	top_right;
	t_vector	bottom_left;
}	t_fractal;

typedef struct s_point_distances
{
	long double	top;
	long double	bottom;
	long double	left;
	long double	right;
}	t_point_distances;

typedef struct s_scroll_hook_param
{
	mlx_image_t		*img;
	mlx_t			*mlx;
}	t_scroll_hook_param;

// typedef struct s_rgba
// {
// 	int	r;
// 	int	g;
// 	int	b;
// 	int	a;
// }	t_rgba;

t_complex	*ft_add_complex(t_complex *c1, t_complex *c2, t_complex *res);

t_complex	*ft_subtract_complex(t_complex *c1, t_complex *c2, t_complex *res);

t_complex	*ft_multiply_complex(t_complex *c1, t_complex *c2, t_complex *res);

t_complex	*ft_divide_complex(t_complex *c1, t_complex *c2, t_complex *res);

long double		ft_squared_absolute_complex(t_complex c);

int			mandelbrot(t_complex c);

#endif
