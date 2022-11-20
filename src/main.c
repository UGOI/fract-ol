/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:29:06 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/21 00:23:03 by sdukic           ###   ########.fr       */
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

void ft_zoom(t_fractal fractal, float enlargement_ratio, t_vector zoom_point, int reset)
{
	t_fractal 			temp_fractal;
	t_point_distances	distances;
	float				base;
	static float		exponent;

	if (!exponent)
		exponent = 1;
	if (reset)
		exponent = 1;
	distances.top = fractal.top_left.y - zoom_point.y;
	distances.botton = zoom_point.y - fractal.bottom_left.y;
	distances.left = fractal.top_left.x - zoom_point.x;
	distances.right = zoom_point.x - fractal.top_right.x;
	base = 1 /enlargement_ratio;

//If 1 trash
	if (distance.top < distance.bottom)
	{
		temp_fractal.top_left.y = zoom_point.y + distances.bottom * powf(base, exponent);
		temp_fractal.top_right.y = temp_fractal.top_left.y;
		temp_fractal.bottom_left.y = zoom_point.y - distances.bottom * powf(base, exponent);
	}
	else if (distance.top >= distance.bottom)
	{
		temp_fractal.top_left.y = zoom_point.y + distances.top * powf(base, exponent);
		temp_fractal.top_right.y = temp_fractal.top_left.y;
		temp_fractal.bottom_left.y = zoom_point.y - distances.top * powf(base, exponent);
	}

	if (distance.right < distance.left)
	{
		temp_fractal.top_left.x = zoom_point.x - distances.left * powf(base, exponent);
		temp_fractal.bottom_left.x = temp_fractal.top_left.x;
		temp_fractal.top_right.x = zoom_point.x + distances.left * powf(base, exponent);
	}
	else if (distance.right >= distance.left)
	{
		temp_fractal.top_left.x = zoom_point.x - distances.right * powf(base, exponent);
		temp_fractal.bottom_left.x = temp_fractal.top_left.x;
		temp_fractal.top_right.x = zoom_point.x + distances.right * powf(base, exponent);
	}

//If 2 trash
	if (distance.top < distance.bottom)
	{
		fractal.bottom_left.y = temp_fractal.bottom_left.y;
	}
	else if (distance.top >= distance.bottom)
	{
		fractal.top_left.y = temp_fractal.top_left.y;
		fractal.top_right.y = temp_fractal.top_right.y;
	}

	if (distance.right < distance.left)
	{
		fractal.top_left.x = temp_fractal.top_left.x;
		fractal.bottom_left.x = temp_fractal.bottom_left.x;
	}
	else if (distance.right >= distance.left)
	{
		fractal.top_right.x = temp_fractal.top_right.x;
	}
	exponent++;
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
	ft_draw_fractal(img, mandelbrot, screen_dimensions);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();

	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
