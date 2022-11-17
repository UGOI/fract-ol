/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:29:06 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/17 17:07:27 by sdukic           ###   ########.fr       */
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

void ft_draw_fractal(mlx_image_t *img, float pixel_size, float top_left, float width)
{
	uint32_t	iter;
	uint32_t	iter2;
	t_complex	c;

	iter = 0;
	iter2 = 0;
	while (iter++ < pixel_size)
	{
		c.real = top_left + width / pixel_size * (float)iter;
		while (iter2++ < pixel_size)
		{
			c.imaginary = -top_left - width / pixel_size * (float)iter2;
			if (mandelbrot(c) == 0)
				mlx_put_pixel(img, iter, iter2, 255);
		}
	iter2 = 0;
	}
}

int32_t	main(void)
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
		error();
	mlx_image_t* img = mlx_new_image(mlx, 1000, 1000);
	if (!img)
		error();
	ft_draw_fractal(img, 1000, -1, 2);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();

	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
