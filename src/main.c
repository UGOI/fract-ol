/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:29:06 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/17 05:32:23 by sdukic           ###   ########.fr       */
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

void ft_draw_fractal(mlx_image_t *img, float x)
{
	uint32_t	iter;
	uint32_t	iter2;
	t_complex	c;

	iter = 0;
	iter2 = 0;
	while (iter++ < x)
	{
		c.real = -2.0 + 4.0 / x * (float)iter;
		// printf("%f\n", -2.0 + 4.0 / 100.0 * (float)iter);
		while (iter2++ < x)
		{
			c.imaginary = 2.0 - 4.0 / x * (float)iter2;
			// printf("%f, %f\n", c.real, c.imaginary);
			// printf("\n%d\n", mandelbrot(c));
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
	mlx_image_t* img = mlx_new_image(mlx, 512, 512);
	if (!img)
		error();
	ft_draw_fractal(img, 512);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();

	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
