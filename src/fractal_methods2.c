/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_methods2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:01:25 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/30 21:06:29 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"

void	set_fractal_col_shift(t_fractal *fractal,
	float col_shift)
{
	fractal->col_shift = col_shift;
}

void	set_fractal_name(t_fractal *fractal,
	char *name)
{
	fractal->name = name;
}

void	set_fractal_frame(t_fractal *fractal,
	t_frame frame)
{
	fractal->frame = frame;
}
