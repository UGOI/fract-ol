/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:29:30 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/30 13:01:19 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"
#include "../lib/libft/libft.h"

int	ft_fractal_initialized(t_fractal fractal)
{
	return (
		!(fractal.top_left.x == 0 && fractal.top_left.y
			== 0 && fractal.dim.x == 0 && fractal.dim.y == 0)
	);
}

void	ft_initialize_fractal(t_fractal *fractal, char *name, t_complex c)
{
	if (!ft_strcmp(name, "julia"))
		ft_initialize_julia(fractal, c);
	else if (!ft_strcmp(name, "eye"))
		ft_initialize_eye(fractal);
	else if (!ft_strcmp(name, "mandelbrot3"))
		ft_initialize_mandelbrot3(fractal);
	else if (!ft_strcmp(name, "mandelbrot4"))
		ft_initialize_mandelbrot4(fractal);
	else
		ft_initialize_mandelbrot(fractal);
}
