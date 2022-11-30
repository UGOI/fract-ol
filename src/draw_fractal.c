/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:29:06 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/30 13:19:57 by sdukic           ###   ########.fr       */
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
	steps = ft_get_steps(fractal.dim, img);
	while (iter.x < ((long double)img->width))
	{
		c.real = fractal.top_left.x + steps.x * (long double)iter.x;
		while (iter.y < ((long double)img->height))
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

void	draw_fractal_func(mlx_image_t *img, t_fractal fractal, t_vector iter, t_complex c)
{
	int			iterations;

	if (!ft_strcmp(fractal.name, "julia"))
		iterations = fractal.func2(c, fractal.constant);
	else
		iterations = fractal.func(c);
	mlx_put_pixel(img, iter.x, iter.y,
		ft_sinus_colors(iterations, fractal.col_shift));
}

void	ft_draw_fractal2(mlx_image_t *img, t_fractal fractal)
{
	t_vector	iter;
	t_complex	c;
	t_vector	steps;

	iter = fractal.frame.top_left;
	steps = ft_get_steps2(fractal.dim, fractal.frame);
	while (iter.x <= fractal.frame.top_left.x + ((long double)fractal.frame.width))
	{
		c.real = fractal.top_left.x + steps.x * ((long double)iter.x - fractal.frame.top_left.x);
		while (iter.y <= fractal.frame.top_left.y + ((long double)fractal.frame.height))
		{
			c.imaginary = fractal.top_left.y - steps.y * ((long double)iter.y - fractal.frame.top_left.y);
			draw_fractal_func(img, fractal, iter, c);
			iter.y++;
		}
	iter.x++;
	iter.y = fractal.frame.top_left.y;
	}
}
