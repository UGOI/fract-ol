/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:54:38 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/30 22:46:02 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include "MLX42/MLX42.h"
# define ITER 100
# define RGB_MAX 16777215
# define WIDTH 500
# define HEIGHT 500

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
	t_vector	dim;
	char		*name;
	t_complex	constant;
	int			(*func)(t_complex);
	int			(*func2)(t_complex, t_complex);
	float		col_shift;
	t_frame		frame;
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

//Fractal methods
void		set_fractal_top_left(t_fractal *fractal, t_vector top_left);

void		set_fractal_dim(t_fractal *fractal, t_vector dim);

void		set_fractal_constant(t_fractal *fractal, t_complex constant);

void		set_fractal_func(t_fractal *fractal, int (*func)(t_complex));

void		set_fractal_func2(t_fractal *fractal,
				int (*func)(t_complex z, t_complex c));

void		set_fractal_col_shift(t_fractal *fractal, float col_shift);

void		set_fractal_name(t_fractal *fractal, char *name);

void		set_fractal_frame(t_fractal *fractal, t_frame frame);

//Complex operations

t_complex	ft_add_complex(t_complex c1, t_complex c2);

t_complex	ft_subtract_complex(t_complex c1, t_complex c2);

t_complex	ft_multiply_complex(t_complex c1, t_complex c2);

t_complex	ft_power_complex(t_complex c1, long double pow);

t_complex	ft_divide_complex(t_complex c1, t_complex c2);

// Vector operations

t_vector	add_vector(t_vector v1, t_vector v2);

t_vector	sub_vector(t_vector v1, t_vector v2);

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

void		change_color_for_each_pixel(t_scroll_hook_param *shp);

//mlx_get_pixel
uint32_t	mlx_get_pixel_color(mlx_image_t *image, uint32_t x, uint32_t y);

//Fractal Init

void		ft_initialize_mandelbrot(t_fractal *fractal);

void		ft_initialize_julia(t_fractal *fractal, t_complex constant);

void		ft_initialize_eye(t_fractal *fractal);

void		ft_initialize_mandelbrot3(t_fractal *fractal);

void		ft_initialize_mandelbrot4(t_fractal *fractal);

int			ft_fractal_initialized(t_fractal fractal);

//Fractal Init utils

void		ft_initialize_fractal(t_fractal *fractal, char *name, t_complex c);

//Zoom
long double	ft_get_zoom_point_comp(long double zoom_point_comp,
				long double d_comp, int direction);

t_fractal	ft_get_zoomed_fractal(t_fractal fractal,
				t_vector zoom_point, int direction);

void		ft_zoom(t_vector zoom_point_screen, int direction,
				t_scroll_hook_param *shp);

//Draw Fractal
void		ft_erase_img_content(mlx_image_t *img);

t_vector	ft_get_steps(t_vector dim, mlx_image_t *img);

t_vector	ft_get_steps2(t_vector dim, t_frame frame);

void		ft_draw_fractal(mlx_image_t *img, t_fractal fractal);

void		ft_draw_fractal2(mlx_image_t *img, t_fractal fractal);

void		draw_fractal_func(mlx_image_t *img, t_fractal fractal,
				t_vector iter, t_complex c);

//Hooks
void		my_scrollhook(double xdelta, double ydelta, void *param);

void		my_resizehook(int32_t width, int32_t height, void *param);

void		my_keyhook(mlx_key_data_t keydata, void *param);

void		exit_safely(t_scroll_hook_param *shp);

//Translate Utils
void		shift_fract_coord(t_fractal *fractal,
				t_vector coordinate_translation);

void		put_trans_fract(mlx_image_t *img,
				t_vector iter, t_vector pix_trans);

t_fractal	get_fract_sect(t_fractal fract, t_vector cord_trans);

void		set_frame(mlx_image_t *img, t_vector pix_trans, t_fractal *fract);

//Translate
void		trans_fract_left(t_scroll_hook_param *shp,
				t_vector pix_trans);

void		trans_fract_right(t_scroll_hook_param *shp,
				t_vector pix_trans);

void		trans_fract_up(t_scroll_hook_param *shp,
				t_vector pix_trans);

void		trans_fract_down(t_scroll_hook_param *shp,
				t_vector pix_trans);

//RGBA
int			get_rgba(int r, int g, int b, int a);

int			get_r(int rgba);

int			get_g(int rgba);

int			get_b(int rgba);

int			get_a(int rgba);

#endif
