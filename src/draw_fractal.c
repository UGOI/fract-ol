/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:29:06 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/24 21:54:17 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <memory.h>
#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"
#define WIDTH 5120
#define HEIGHT 2880

void	ft_erase_img_content(mlx_image_t *img)
{
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
}

t_vector	ft_get_fractal_dimensions(t_fractal fractal)
{
	t_vector	dim;

	dim.x = fractal.top_right.x - fractal.top_left.x;
	dim.y = fractal.top_left.y - fractal.bottom_left.y;
	return (dim);
}

t_vector	ft_get_steps(t_vector dim, mlx_image_t *img)
{
	t_vector	steps;

	steps.x = dim.x / (long double)img->width;
	steps.y = dim.y / (long double)img->height;
	return (steps);
}

t_vector	ft_get_steps2(t_vector dim, t_monitor_size m_size)
{
	t_vector	steps;

	steps.x = dim.x / (long double)m_size.x;
	steps.y = dim.y / (long double)m_size.y;
	return (steps);
}

void	ft_draw_fractal(mlx_image_t *img, t_fractal fractal)
{
	t_vector	function_dimensions;
	t_vector	iter;
	t_complex	c;
	t_vector	steps;
	int			iterations;

	iter = (t_vector){0, 0};
	ft_erase_img_content(img);
	function_dimensions = ft_get_fractal_dimensions(fractal);
	steps = ft_get_steps(function_dimensions, img);
	while (iter.x < ((long double)img->width - 1))
	{
		c.real = fractal.top_left.x + steps.x * (long double)iter.x;
		while (iter.y < ((long double)img->height - 1))
		{
			c.imaginary = fractal.top_left.y - steps.y * (long double)iter.y;
			if (!strcmp(fractal.name, "julia"))
				iterations = fractal.func2(c, fractal.constant);
			else
				iterations = fractal.func(c);
			mlx_put_pixel(img, iter.x, iter.y,
				ft_sinus_colors(iterations, fractal.col_shift));
			iter.y++;
		}
	iter.x++;
	iter.y = 0;
	}
}

void	ft_draw_fractal2(mlx_image_t *img, t_fractal fractal, t_monitor_size m_size)
{
	t_vector	function_dimensions;
	t_vector	iter;
	t_complex	c;
	t_vector	steps;
	int			iterations;

	ft_erase_img_content(img);
	function_dimensions = ft_get_fractal_dimensions(fractal);
	steps = ft_get_steps2(function_dimensions, m_size);
	while (iter.x < ((long double)m_size.x - 1))
	{
		c.real = fractal.top_left.x + steps.x * (long double)iter.x;
		while (iter.y < ((long double)m_size.y - 1))
		{
			c.imaginary = fractal.top_left.y - steps.y * (long double)iter.y;
			if (!strcmp(fractal.name, "julia"))
				iterations = fractal.func2(c, fractal.constant);
			else
				iterations = fractal.func(c);
			mlx_put_pixel(img, iter.x, iter.y,
				ft_sinus_colors(iterations, fractal.col_shift));
			iter.y++;
		}
	iter.x++;
	iter.y = 0;
	}
}

// int32_t	main(void)
// {
// 	t_complex c1 = {2, 6};
// 	t_complex c2 = {-2, 9};
// 	t_complex res;

// 	res = ft_divide_complex(c1, c2);

// 	printf("%Lf %+Lfi\n", res.real, res.imaginary);
// }
