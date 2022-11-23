/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:29:30 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/23 21:45:48 by sdukic           ###   ########.fr       */
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

void	ft_initialize_mandelbrot(t_fractal *mandelbrot)
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
}

void	ft_initialize_julia(t_fractal *julia)
{
	julia->top_left.x = -2.5;
	julia->top_left.y = 2;
	julia->top_right.x = 1.5;
	julia->top_right.y = 2;
	julia->bottom_left.x = -2.5;
	julia->bottom_left.y = -2;
	julia->julia = 1;
	julia->constant.real = 0;
	julia->constant.imaginary = 0;
}
