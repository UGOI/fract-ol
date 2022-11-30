/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:01:25 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/30 14:08:25 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"

//getters and seters
// typedef struct s_fractal
// {
// 	t_vector	top_left;
// 	t_vector	dim;
// 	t_vector	top_right;
// 	t_vector	bottom_left;
// 	int			julia;
// 	char		*name;
// 	t_complex	constant;
// 	int			(*func)(t_complex);
// 	int			(*func2)(t_complex, t_complex);
// 	float		col_shift;
// 	t_frame		frame;
// }	t_fractal;

void	set_fractal_top_left(t_fractal *fractal, t_vector top_left)
{
	fractal->top_left = top_left;
}

void	set_fractal_dim(t_fractal *fractal, t_vector dim)
{
	fractal->dim = dim;
}

void	set_fractal_constant(t_fractal *fractal, t_complex constant)
{
	fractal->constant = constant;
}

void	set_fractal_func(t_fractal *fractal, int (*func)(t_complex))
{
	fractal->func = func;
}

void	set_fractal_func2(t_fractal *fractal, int (*func)(t_complex z, t_complex c))
{
	fractal->func2 = func;
}

void	set_fractal_col_shift(t_fractal *fractal, float col_shift)
{
	fractal->col_shift = col_shift;
}

void	set_fractal_name(t_fractal *fractal, char *name)
{
	fractal->name = name;
}

void	set_fractal_frame(t_fractal *fractal, t_frame frame)
{
	fractal->frame = frame;
}
