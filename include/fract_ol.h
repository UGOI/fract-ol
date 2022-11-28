/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:54:38 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/28 17:29:21 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include "MLX42/MLX42.h"
# define ITER 100
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

typedef struct s_vector_uint32_t
{
	uint32_t	x;
	uint32_t	y;
}	t_vector_uint_32_t;

typedef struct s_monitor_size
{
	int32_t	x;
	int32_t	y;
}	t_monitor_size;

typedef struct s_frame
{
	int32_t		width;
	int32_t		height;
	t_vector	top_left;
}	t_frame;

typedef struct s_fractal
{
	t_vector	top_left;
	t_vector	top_right;
	t_vector	bottom_left;
	int			julia;
	char		*name;
	t_complex	constant;
	int			(*func)(t_complex);
	int			(*func2)(t_complex, t_complex);
	float		col_shift;
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

t_complex	ft_add_complex(t_complex c1, t_complex c2);

t_complex	ft_subtract_complex(t_complex c1, t_complex c2);

t_complex	ft_multiply_complex(t_complex c1, t_complex c2);

t_complex	ft_power_complex(t_complex c1, long double pow);

t_complex	ft_divide_complex(t_complex c1, t_complex c2);

long double	ft_squared_absolute_complex(t_complex c);

int			mandelbrot(t_complex c);

int			julia(t_complex z, t_complex c);

int			eye(t_complex c);

int			mandelbrot3(t_complex c);

int			mandelbrot4(t_complex c);

//Colors
int			get_rgba(int r, int g, int b, int a);

int			ft_sinus_colors(int iterations, float shift);

int			ft_ordered_linear_colors(int iterations);

void		shift_color(t_scroll_hook_param *shp, long double translation);

//mlx_get_pixel
uint32_t	mlx_get_pixel_color(mlx_image_t *image, uint32_t x, uint32_t y);

//Fractal Init

void		ft_initialize_mandelbrot(t_fractal *fractal);

void		ft_initialize_julia(t_fractal *fractal, t_complex constant);

void		ft_initialize_eye(t_fractal *mandelbrot);

void		ft_initialize_mandelbrot3(t_fractal *fractal);

void		ft_initialize_mandelbrot4(t_fractal *fractal);

int			ft_fractal_initialized(t_fractal fractal);

//Fractal Init utils

void		ft_initialize_fractal(t_fractal *fractal, char *name, t_complex c);

//Zoom
long double	ft_get_zoom_point_comp(long double zoom_point_comp, long double d_comp, int direction);

t_fractal	ft_get_zoomed_fractal(t_fractal fractal, t_vector zoom_point, int direction);

void		ft_zoom(t_vector zoom_point_screen, int direction, t_scroll_hook_param *shp);

//Draw Fractal
void		ft_erase_img_content(mlx_image_t *img);

t_vector	ft_get_fractal_dimensions(t_fractal fractal);

t_vector	ft_get_steps(t_vector dim, mlx_image_t *img);

t_vector	ft_get_steps2(t_vector dim, t_frame frame);

void		ft_draw_fractal(mlx_image_t *img, t_fractal fractal);

void		ft_draw_fractal2(mlx_image_t *img, t_fractal fractal, t_frame frame);

void		draw_fractal_func(mlx_image_t *img, t_fractal fractal, t_vector iter, t_complex c);

//Hooks
void		my_scrollhook(double xdelta, double ydelta, void *param);

void		my_resizehook(int32_t width, int32_t height, void *param);

void		my_keyhook(mlx_key_data_t keydata, void *param);

void		exit_safely(t_scroll_hook_param *shp);

void	translate_fractal_horizontal(t_scroll_hook_param *shp,
long double translation);

void	translate_fractal_vertical(t_scroll_hook_param *shp,
long double translation);

void	trans_fract_left(t_scroll_hook_param *shp,
t_vector_uint_32_t pix_trans);

void	trans_fract_right(t_scroll_hook_param *shp,
t_vector_uint_32_t pix_trans);

void	trans_fract_up(t_scroll_hook_param *shp,
t_vector_uint_32_t pix_trans);

#endif
