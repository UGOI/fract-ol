/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:29:30 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/24 10:39:02 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
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

void	ft_initialize_fractal(t_fractal *fractal, char *name, t_complex c)
{
	if (!strcmp(name, "julia"))
		ft_initialize_julia(fractal, c);
	else if (!strcmp(name, "eye"))
		ft_initialize_eye(fractal);
	else if (!strcmp(name, "mandelbrot3"))
		ft_initialize_mandelbrot3(fractal);
	else if (!strcmp(name, "mandelbrot4"))
		ft_initialize_mandelbrot4(fractal);
	else
		ft_initialize_mandelbrot(fractal);
}
