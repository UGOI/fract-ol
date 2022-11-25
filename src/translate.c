/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:28:50 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/26 00:33:19 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	translate_fractal_horizontal(t_scroll_hook_param *shp,
long double translation)
{
	shp->fractal.top_left.x += translation;
	shp->fractal.top_right.x += translation;
	shp->fractal.bottom_left.x += translation;
	ft_draw_fractal(shp->img, shp->fractal);
	return ;
}

void	translate_fractal_vertical(t_scroll_hook_param *shp,
long double translation)
{
	shp->fractal.top_left.y += translation;
	shp->fractal.top_right.y += translation;
	shp->fractal.bottom_left.y += translation;
	ft_draw_fractal(shp->img, shp->fractal);
	return ;
}
