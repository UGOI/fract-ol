/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:29:06 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/27 17:27:59 by sdukic           ###   ########.fr       */
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
#include "../lib/libft/ft_printf.h"
#include "../lib/libft/libft.h"
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

t_vector	ft_get_steps2(t_vector dim, t_frame frame)
{
	t_vector	steps;

	steps.x = dim.x / (long double)frame.width;
	steps.y = dim.y / (long double)frame.height;
	return (steps);
}

void	ft_draw_fractal(mlx_image_t *img, t_fractal fractal)
{
	t_vector	iter;
	t_complex	c;
	t_vector	steps;
	int			iterations;

	iter = (t_vector){0, 0};
	steps = ft_get_steps(ft_get_fractal_dimensions(fractal), img);
	while (iter.x < ((long double)img->width - 1))
	{
		c.real = fractal.top_left.x + steps.x * (long double)iter.x;
		while (iter.y < ((long double)img->height - 1))
		{
			c.imaginary = fractal.top_left.y - steps.y * (long double)iter.y;
			if (!ft_strcmp(fractal.name, "julia"))
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

void	ft_draw_fractal2(mlx_image_t *img, t_fractal fractal, t_frame frame)
{
	t_vector	iter;
	t_complex	c;
	t_vector	steps;
	int			iterations;

	iter = frame.top_left;
	steps = ft_get_steps2(ft_get_fractal_dimensions(fractal), frame);
	printf("%Lf, %Lf\n", iter.x, frame.top_left.x + ((long double)frame.width - 1));
	printf("%Lf, %Lf\n", iter.y, frame.top_left.y + ((long double)frame.height - 1));
	printf("%Lf, %Lf, %Lf, %Lf, %Lf, %Lf\n", fractal.top_left.x, fractal.top_left.y, fractal.top_right.x, fractal.top_right.y, fractal.bottom_left.x, fractal.bottom_left.y);
	while (iter.x < frame.top_left.x + ((long double)frame.width - 1))
	{

		c.real = fractal.top_left.x + steps.x * ((long double)iter.x - frame.top_left.x);
		while (iter.y < frame.top_left.y + ((long double)frame.height - 1))
		{
			c.imaginary = fractal.top_left.y - steps.y * ((long double)iter.y - frame.top_left.y);
			if (!ft_strcmp(fractal.name, "julia"))
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
