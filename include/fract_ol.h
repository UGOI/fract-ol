/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:54:38 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/23 22:01:37 by sdukic           ###   ########.fr       */
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
	int			julia;
	t_complex	constant;
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
	t_fractal		fractal;
}	t_scroll_hook_param;

t_complex	*ft_add_complex(t_complex *c1, t_complex *c2, t_complex *res);

t_complex	*ft_subtract_complex(t_complex *c1, t_complex *c2, t_complex *res);

t_complex	*ft_multiply_complex(t_complex *c1, t_complex *c2, t_complex *res);

t_complex	*ft_divide_complex(t_complex *c1, t_complex *c2, t_complex *res);

long double	ft_squared_absolute_complex(t_complex c);

int			mandelbrot_eq(t_complex c, int julia, t_complex constant);

// int			julia(t_complex z);

//Colors
int			get_rgba(int r, int g, int b, int a);

int			ft_sinus_colors(int iterations);

int			ft_ordered_linear_colors(int iterations);

//Fractal Utils
void	ft_draw_fractal(mlx_image_t *img, t_fractal fractal);

void		ft_initialize_mandelbrot(t_fractal *mandelbrot);

void		ft_initialize_julia(t_fractal *julia);

int			ft_fractal_initialized(t_fractal fractal);


//Zoom
long double	ft_get_zoom_point_comp(long double zoom_point_comp, long double d_comp, int direction);

t_fractal	ft_get_zoomed_fractal(t_fractal fractal, t_vector zoom_point, int direction);

void 		ft_zoom(t_vector zoom_point, mlx_image_t *img, int direction, t_fractal fractal);

#endif
