/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:29:06 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/21 16:37:42 by sdukic           ###   ########.fr       */
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

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void ft_draw_fractal(mlx_image_t *img, t_fractal fractal, t_vector screen_dimensions)
{
	t_vector	function_dimensions;
	t_vector	iter;
	t_complex	c;
	t_vector	steps;

	function_dimensions.x = fractal.top_right.x - fractal.top_left.x;
	function_dimensions.y = fractal.top_left.y - fractal.bottom_left.y;
	iter.x = 0;
	iter.y = 0;
	steps.x = function_dimensions.x / screen_dimensions.x;
	steps.y = function_dimensions.y / screen_dimensions.y;
	while (iter.x < (screen_dimensions.x - 1))
	{
		c.real = fractal.top_left.x + steps.x * (float)iter.x;
		while (iter.y < (screen_dimensions.y - 1))
		{
			c.imaginary = fractal.top_left.y - steps.y * (float)iter.y;
			if (mandelbrot(c) == 0)
				mlx_put_pixel(img, iter.x, iter.y, 255);
			iter.y++;
		}
	iter.x++;
	iter.y = 0;
	}
}

float	ft_get_point_comp(float zoom_point_comp, float d_comp)
{
	float		res;
	float		base;

	base = 0.95;
	res = zoom_point_comp + d_comp * base;
	return (res);
}

t_fractal	ft_get_zoomed_fractal(t_fractal fractal, t_vector zoom_point)
{
	t_fractal			zoom_fractal;
	t_point_distances	distances;
	float				base;

	distances.top = fractal.top_left.y - zoom_point.y;
	distances.bottom = zoom_point.y - fractal.bottom_left.y;
	distances.left = fractal.top_left.x - zoom_point.x;
	distances.right = zoom_point.x - fractal.top_right.x;
	zoom_fractal.top_left.x = ft_get_point_comp(zoom_point.x, -distances.left);
	zoom_fractal.top_left.y = ft_get_point_comp(zoom_point.y, distances.top);
	zoom_fractal.bottom_left.x = zoom_fractal.top_left.x;
	zoom_fractal.bottom_left.y = ft_get_point_comp(zoom_point.y, -distances.bottom);
	zoom_fractal.top_right.x = ft_get_point_comp(zoom_point.x, distances.right);
	zoom_fractal.top_right.y = zoom_fractal.top_left.y;
	return (zoom_fractal);
}

void	my_scrollhook(double xdelta, double ydelta, void* param)
{
	// Simple up or down detection.
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");

	// Can also detect a mousewheel that go along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}

int32_t	main(void)
{
	t_vector		screen_dimensions;
	t_fractal		initial_mandelbrot;
	t_fractal		mandelbrot;
	mlx_t*			mlx;
	mlx_image_t*	img;

	screen_dimensions.x = 1000;
	screen_dimensions.y = 1000;
	initial_mandelbrot.top_left.x = -2;
	initial_mandelbrot.top_left.y = 2;
	initial_mandelbrot.top_right.x = 2;
	initial_mandelbrot.top_right.y = 2;
	initial_mandelbrot.bottom_left.x = -2;
	initial_mandelbrot.bottom_left.y = -2;

	mandelbrot.top_left.x = initial_mandelbrot.top_left.x;
	mandelbrot.top_left.y = initial_mandelbrot.top_left.y;
	mandelbrot.top_right.x = initial_mandelbrot.top_right.x;
	mandelbrot.top_right.y = initial_mandelbrot.top_right.y;
	mandelbrot.bottom_left.x = initial_mandelbrot.bottom_left.x;
	mandelbrot.bottom_left.y = initial_mandelbrot.bottom_left.y;

	mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
		error();
	img = mlx_new_image(mlx, 5120, 2880);
	if (!img)
		error();
	mlx_scroll_hook(mlx, &my_scrollhook, NULL);
	ft_draw_fractal(img, mandelbrot, screen_dimensions);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
