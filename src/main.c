/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:29:06 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/20 21:09:08 by sdukic           ###   ########.fr       */
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

// void ft_draw_fractal(mlx_image_t *img, float x_pixels, float y_pixels, float left_x, float width)
// {
// 	int	iter;
// 	int	iter2;
// 	t_complex	c;
// 	float		x_steps;
// 	float		y_steps;

// 	iter = 0;
// 	iter2 = 0;
// 	if (x_pixels > y_pixels)
// 	{
// 		x_steps = width / x_pixels;
// 		y_steps = width / x_pixels;
// 	}
// 	else
// 	{
// 		x_steps = width / y_pixels;
// 		y_steps = width / y_pixels;
// 	}
// 	while (iter < (x_pixels - 1))
// 	{
// 		c.real = left_x + width / x_pixels * (float)iter;
// 		while (iter2 < (y_pixels - 1))
// 		{
// 			c.imaginary = -left_x - width / x_pixels * (float)iter2;
// 			if (mandelbrot(c) == 0)
// 				mlx_put_pixel(img, iter, iter2, 255);
// 			iter2++;
// 		}
// 	iter++;
// 	iter2 = 0;
// 	}
// }

void ft_draw_fractal2(mlx_image_t *img, t_fractal fractal, t_vector screen_dimensions)
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

int32_t	main(void)
{
	t_vector screen_dimensions;
	t_fractal mandelbrot;

	screen_dimensions.x = 1000;
	screen_dimensions.y = 1000;

	mandelbrot.top_left.x = -2;
	mandelbrot.top_left.y = 2;
	mandelbrot.top_right.x = 2;
	mandelbrot.top_right.y = 2;
	mandelbrot.bottom_left.x = -2;
	mandelbrot.bottom_left.y = -2;

	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
		error();
	mlx_image_t* img = mlx_new_image(mlx, 5120, 2880);
	if (!img)
		error();
	// ft_draw_fractal(img, 1000, 1000, -2, 4);
	ft_draw_fractal2(img, mandelbrot, screen_dimensions);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();

	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
