/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:29:30 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/24 21:57:32 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"

void	ft_initialize_mandelbrot(t_fractal *fractal)
{
	fractal->top_left.x = -2.5;
	fractal->top_left.y = 2;
	fractal->top_right.x = 1.5;
	fractal->top_right.y = 2;
	fractal->bottom_left.x = -2.5;
	fractal->bottom_left.y = -2;
	fractal->julia = 0;
	fractal->constant.real = 0;
	fractal->constant.imaginary = 0;
	fractal->col_shift = 0.0f;
	fractal->name = "mandelbrot";
	fractal->func = &mandelbrot;
}

void	ft_initialize_julia(t_fractal *fractal, t_complex constant)
{
	fractal->top_left.x = -2.5;
	fractal->top_left.y = 2;
	fractal->top_right.x = 1.5;
	fractal->top_right.y = 2;
	fractal->bottom_left.x = -2.5;
	fractal->bottom_left.y = -2;
	fractal->julia = 1;
	fractal->constant = constant;
	fractal->col_shift = 0.0f;
	fractal->name = "julia";
	fractal->func2 = &julia;
}

void	ft_initialize_eye(t_fractal *mandelbrot)
{
	mandelbrot->top_left.x = -2.5;
	mandelbrot->top_left.y = 2;
	mandelbrot->top_right.x = 1.5;
	mandelbrot->top_right.y = 2;
	mandelbrot->bottom_left.x = -2.5;
	mandelbrot->bottom_left.y = -2;
	mandelbrot->julia = 0;
	mandelbrot->constant.real = 0;
	mandelbrot->constant.imaginary = 0;
	mandelbrot->name = "eye";
	mandelbrot->func = &eye;
}

void	ft_initialize_mandelbrot3(t_fractal *fractal)
{
	fractal->top_left.x = -2.5;
	fractal->top_left.y = 2;
	fractal->top_right.x = 1.5;
	fractal->top_right.y = 2;
	fractal->bottom_left.x = -2.5;
	fractal->bottom_left.y = -2;
	fractal->julia = 0;
	fractal->constant.real = 0;
	fractal->constant.imaginary = 0;
	fractal->col_shift = 0.0f;
	fractal->name = "mandelbrot3";
	fractal->func = &mandelbrot3;
}

void	ft_initialize_mandelbrot4(t_fractal *fractal)
{
	fractal->top_left.x = -2.5;
	fractal->top_left.y = 2;
	fractal->top_right.x = 1.5;
	fractal->top_right.y = 2;
	fractal->bottom_left.x = -2.5;
	fractal->bottom_left.y = -2;
	fractal->julia = 0;
	fractal->constant.real = 0;
	fractal->constant.imaginary = 0;
	fractal->col_shift = 0.0f;
	fractal->name = "mandelbrot4";
	fractal->func = &mandelbrot4;
}
