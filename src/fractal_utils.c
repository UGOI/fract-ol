/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:29:30 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/24 04:56:11 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"

int	ft_fractal_initialized(t_fractal fractal)
{
	return (
		!(fractal.bottom_left.x == 0 && fractal.bottom_left.y == 0
			&& fractal.top_left.x == 0 && fractal.top_left.y
			== 0 && fractal.top_right.x == 0
			&& fractal.top_right.y == 0)
	);
}

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
	fractal->name = "julia";
	fractal->func2 = &julia;
}

void	ft_initialize_nova(t_fractal *mandelbrot)
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
	mandelbrot->name = "nova";
	mandelbrot->func = &nova;
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
	fractal->name = "mandelbrot4";
	fractal->func = &mandelbrot4;
}
