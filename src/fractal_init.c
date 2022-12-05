/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:29:30 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/05 10:27:56 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"

void	ft_initialize_mandelbrot(t_fractal *fractal, t_vector screen_dim)
{
	(void)screen_dim;
	set_fractal_top_left(fractal, (t_vector){-2.5, 2});
	set_fractal_dim(fractal, (t_vector){4, 4.0
		/ screen_dim.x * screen_dim.y});
	set_fractal_constant(fractal, (t_complex){0, 0});
	set_fractal_name(fractal, "mandelbrot");
	set_fractal_col_shift(fractal, 0.5f);
	set_fractal_func(fractal, &mandelbrot);
	set_fractal_frame(fractal,
		(t_frame){screen_dim.x - 1, screen_dim.y - 1, (t_vector){0, 0}});
}

void	ft_initialize_julia(t_fractal *fractal, t_complex constant)
{
	set_fractal_top_left(fractal, (t_vector){-2.5, 2});
	set_fractal_dim(fractal, (t_vector){4, 4.0
		/ (long double)WIDTH * (long double)HEIGHT});
	set_fractal_constant(fractal, constant);
	set_fractal_name(fractal, "julia");
	set_fractal_col_shift(fractal, 0.0f);
	set_fractal_func2(fractal, &julia);
	set_fractal_frame(fractal, (t_frame){WIDTH - 1,
		HEIGHT - 1, (t_vector){0, 0}});
}

void	ft_initialize_eye(t_fractal *fractal)
{
	set_fractal_top_left(fractal, (t_vector){-2.5, 2});
	set_fractal_dim(fractal, (t_vector){4, 4.0
		/ (long double)WIDTH * (long double)HEIGHT});
	set_fractal_constant(fractal, (t_complex){0, 0});
	set_fractal_name(fractal, "eye");
	set_fractal_col_shift(fractal, 0.5f);
	set_fractal_func(fractal, &eye);
	set_fractal_frame(fractal, (t_frame){WIDTH - 1, HEIGHT - 1,
		(t_vector){0, 0}});
}

void	ft_initialize_mandelbrot3(t_fractal *fractal)
{
	set_fractal_top_left(fractal, (t_vector){-2.5, 2});
	set_fractal_dim(fractal, (t_vector){4, 4.0
		/ (long double)WIDTH * (long double)HEIGHT});
	set_fractal_constant(fractal, (t_complex){0, 0});
	set_fractal_name(fractal, "mandelbrot3");
	set_fractal_col_shift(fractal, 0.5f);
	set_fractal_func(fractal, &mandelbrot3);
	set_fractal_frame(fractal, (t_frame){WIDTH - 1,
		HEIGHT - 1, (t_vector){0, 0}});
}

void	ft_initialize_mandelbrot4(t_fractal *fractal)
{
	set_fractal_top_left(fractal, (t_vector){-2.5, 2});
	set_fractal_dim(fractal, (t_vector){4, 4.0
		/ (long double)WIDTH * (long double)HEIGHT});
	set_fractal_constant(fractal, (t_complex){0, 0});
	set_fractal_name(fractal, "mandelbrot4");
	set_fractal_col_shift(fractal, 0.5f);
	set_fractal_func(fractal, &mandelbrot4);
	set_fractal_frame(fractal, (t_frame){WIDTH - 1,
		HEIGHT - 1, (t_vector){0, 0}});
}
