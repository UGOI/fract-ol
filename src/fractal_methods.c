/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:01:25 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/29 21:07:54 by sdukic           ###   ########.fr       */
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

void	set_fractal_top_right(t_fractal *fractal, t_vector top_right)
{
	fractal->top_right = top_right;
}

void	set_fractal_bottom_left(t_fractal *fractal, t_vector bottom_left)
{
	fractal->bottom_left = bottom_left;
}

void	set_fractal_constant(t_fractal *fractal, t_complex constant)
{
	fractal->constant = constant;
}

void	set_fractal_func(t_fractal *fractal, int (*func)(t_complex))
{
	fractal->func = func;
}

void	set_fractal_col_shift(t_fractal *fractal, float col_shift)
{
	fractal->col_shift = col_shift;
}


//dependency setters
void	set_fractal_points_dep(t_fractal *fractal)
{
	set_fractal_top_right(fractal, (t_vector){fractal->top_left.x + fractal->dim.x, fractal->top_left.y});
	set_fractal_bottom_left(fractal, (t_vector){fractal->top_left.x, fractal->top_left.y - fractal->dim.y});
}
