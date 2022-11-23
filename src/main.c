/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:29:06 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/23 11:37:28 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <memory.h>
#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"
#define WIDTH 5120
#define HEIGHT 2880
#define BPP sizeof(int32_t)

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_erase_img_content(mlx_image_t *img)
{
	memset(img->pixels, 255, img->width * img->height * BPP);
}

void ft_draw_fractal(mlx_image_t *img, t_fractal fractal)
{
	t_vector	function_dimensions;
	t_vector	iter;
	t_complex	c;
	t_vector	steps;

	ft_erase_img_content(img);
	function_dimensions.x = fractal.top_right.x - fractal.top_left.x;
	function_dimensions.y = fractal.top_left.y - fractal.bottom_left.y;
	iter.x = 0;
	iter.y = 0;
	steps.x = function_dimensions.x / (long double)img->width;
	steps.y = function_dimensions.y / (long double)img->height;
	while (iter.x < ((long double)img->width - 1))
	{
		c.real = fractal.top_left.x + steps.x * (long double)iter.x;
		while (iter.y < ((long double)img->height - 1))
		{
			c.imaginary = fractal.top_left.y - steps.y * (long double)iter.y;
			if (mandelbrot(c) == 0)
				mlx_put_pixel(img, iter.x, iter.y, 255);
			iter.y++;
		}
	iter.x++;
	iter.y = 0;
	}
}

long double	ft_get_zoom_point_comp(long double zoom_point_comp, long double d_comp, int direction)
{
	long double		res;
	long double		base;

	base = 0.95;
	if (direction < 0)
		base = 1 / base;
	res = zoom_point_comp + d_comp * base;
	return (res);
}

t_fractal	ft_get_zoomed_fractal(t_fractal fractal, t_vector zoom_point, int direction)
{
	t_fractal			zoom_fractal;
	t_point_distances	distances;

	distances.top = fractal.top_left.y - zoom_point.y;
	distances.bottom = zoom_point.y - fractal.bottom_left.y;
	distances.left = zoom_point.x - fractal.top_left.x;
	distances.right = fractal.top_right.x - zoom_point.x;
	zoom_fractal.top_left.x = ft_get_zoom_point_comp(zoom_point.x, -distances.left, direction);
	zoom_fractal.top_left.y = ft_get_zoom_point_comp(zoom_point.y, distances.top, direction);
	zoom_fractal.bottom_left.x = zoom_fractal.top_left.x;
	zoom_fractal.bottom_left.y = ft_get_zoom_point_comp(zoom_point.y, -distances.bottom, direction);
	zoom_fractal.top_right.x = ft_get_zoom_point_comp(zoom_point.x, distances.right, direction);
	zoom_fractal.top_right.y = zoom_fractal.top_left.y;
	return (zoom_fractal);
}

int	ft_fractal_initialized(t_fractal fractal)
{
	return (
		!(fractal.bottom_left.x == 0 && fractal.bottom_left.y == 0
			&& fractal.top_left.x == 0 && fractal.top_left.y
			== 0 && fractal.top_right.x == 0
			&& fractal.top_right.y == 0)
	);
}

void	ft_initialize_mandelbrot(t_fractal *mandelbrot)
{
	mandelbrot->top_left.x = -2;
	mandelbrot->top_left.y = 2;
	mandelbrot->top_right.x = 2;
	mandelbrot->top_right.y = 2;
	mandelbrot->bottom_left.x = -2;
	mandelbrot->bottom_left.y = -2;
}

void 		ft_zoom(t_vector zoom_point, mlx_image_t *img, int direction)
{
	static t_fractal	zoomed_fractal;


	if (!ft_fractal_initialized(zoomed_fractal))
		ft_initialize_mandelbrot(&zoomed_fractal);
	zoom_point.x = (zoomed_fractal.top_left.x)+(zoom_point.x)/(img->width)*(zoomed_fractal.top_right.x - zoomed_fractal.top_left.x);
	zoom_point.y = (zoomed_fractal.top_left.y)-(zoom_point.y)/(img->height)*(zoomed_fractal.top_left.y - zoomed_fractal.bottom_left.y);;
	// printf("\nx: %Lf, y: %Lf\n", zoom_point.x, zoom_point.y);
	// printf("\nzoomed_fractal.top_left.x: %Lf, zoomed_fractal.top_left.y: %Lf\n", zoomed_fractal.top_left.x, zoomed_fractal.top_left.y);
	zoomed_fractal = ft_get_zoomed_fractal(zoomed_fractal, zoom_point, direction);
	// printf("\nzoomed_fractal.top_left.x: %Lf, zoomed_fractal.top_left.y: %Lf\n", zoomed_fractal.top_left.x, zoomed_fractal.top_left.y);
	ft_draw_fractal(img, zoomed_fractal);
}

void	my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_vector		zoom_point;
	int32_t			x;
	int32_t			y;
	t_scroll_hook_param *scroll_hook_param;

	x = 0;
	y = 0;
	scroll_hook_param = param;
	mlx_get_mouse_pos(scroll_hook_param->mlx, &x, &y);
	zoom_point.x = (long double)x;
	zoom_point.y = (long double)y;
	if (ydelta > 0)
	{
		ft_zoom(zoom_point, scroll_hook_param->img, 1);
		// puts("Up!");
	}
	else if (ydelta < 0)
	{
		ft_zoom(zoom_point, scroll_hook_param->img, -1);
		// puts("Down!");
	}
}

int32_t	main(void)
{
	t_fractal			initial_mandelbrot;
	t_fractal			mandelbrot;
	t_scroll_hook_param scroll_hook_param;

	ft_initialize_mandelbrot(&mandelbrot);
	ft_initialize_mandelbrot(&initial_mandelbrot);
	scroll_hook_param.mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!scroll_hook_param.mlx)
		error();
	scroll_hook_param.img = mlx_new_image(scroll_hook_param.mlx, 500, 500);
	if (!scroll_hook_param.img)
		error();
	mlx_scroll_hook(scroll_hook_param.mlx, &my_scrollhook, &scroll_hook_param);
	ft_draw_fractal(scroll_hook_param.img, mandelbrot);
	if (mlx_image_to_window(scroll_hook_param.mlx, scroll_hook_param.img, 0, 0) < 0)
		error();
	mlx_loop(scroll_hook_param.mlx);
	mlx_delete_image(scroll_hook_param.mlx, scroll_hook_param.img);
	mlx_terminate(scroll_hook_param.mlx);
	return (EXIT_SUCCESS);
}
