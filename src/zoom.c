/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:18:44 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/23 22:09:06 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"

long double	ft_get_zoom_point_comp(long double zoom_point_comp
, long double d_comp, int direction)
{
	long double		res;
	long double		base;

	base = 0.95;
	if (direction < 0)
		base = 1 / base;
	res = zoom_point_comp + d_comp * base;
	return (res);
}

t_fractal	ft_get_zoomed_fractal(t_fractal fractal
, t_vector zoom_point, int direction)
{
	t_fractal			zoom_fractal;
	t_point_distances	distances;

	zoom_fractal = fractal;
	distances.top = fractal.top_left.y - zoom_point.y;
	distances.bottom = zoom_point.y - fractal.bottom_left.y;
	distances.left = zoom_point.x - fractal.top_left.x;
	distances.right = fractal.top_right.x - zoom_point.x;
	zoom_fractal.top_left.x = ft_get_zoom_point_comp(zoom_point.x,
			-distances.left, direction);
	zoom_fractal.top_left.y = ft_get_zoom_point_comp(zoom_point.y,
			distances.top, direction);
	zoom_fractal.bottom_left.x = zoom_fractal.top_left.x;
	zoom_fractal.bottom_left.y = ft_get_zoom_point_comp(zoom_point.y,
			-distances.bottom, direction);
	zoom_fractal.top_right.x = ft_get_zoom_point_comp(zoom_point.x,
			distances.right, direction);
	zoom_fractal.top_right.y = zoom_fractal.top_left.y;
	return (zoom_fractal);
}

void	ft_zoom(t_vector zoom_point
, mlx_image_t *img, int direction, t_fractal fractal)
{
	static t_fractal	zoomed_fractal;

	if (fractal.julia == 0)
	{
		if (!ft_fractal_initialized(zoomed_fractal))
			ft_initialize_mandelbrot(&zoomed_fractal);
	}
	else
	{
		if (!ft_fractal_initialized(zoomed_fractal))
			ft_initialize_julia(&zoomed_fractal);
	}
	zoom_point.x = (zoomed_fractal.top_left.x) + (zoom_point.x)
		/ (img->width) * (zoomed_fractal.top_right.x
			- zoomed_fractal.top_left.x);
	zoom_point.y = (zoomed_fractal.top_left.y) - (zoom_point.y)
		/ (img->height) * (zoomed_fractal.top_left.y
			- zoomed_fractal.bottom_left.y);
	zoomed_fractal = ft_get_zoomed_fractal(zoomed_fractal,
			zoom_point, direction);
	ft_draw_fractal(img, zoomed_fractal);
}
