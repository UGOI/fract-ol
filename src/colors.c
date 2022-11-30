/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:02:47 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/30 23:35:50 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"
#include <math.h>
#include <stdio.h>
#include "../lib/libft/libft.h"
#include "../lib/libft/ft_printf.h"

int	ft_sinus_colors(int iterations, float shift)
{
	if (iterations == 0)
		return (255);
	else
	{
		return (
			get_rgba(
				((sin(iterations * 0.8 + 3.0 + shift) + 1.0) / 2.0 * 255.0),
				((sin(iterations * 0.5 + 4.0 + shift) + 1.0) / 2.0 * 255.0),
				((sin(iterations * 0.3 + 1.0 + shift) + 1.0) / 2.0 * 255.0),
				255));
	}
}

int	ft_ordered_linear_colors(int iterations)
{
	if (iterations == 0)
		return (255);
	else
	{
		return ((RGB_MAX * iterations / ITER << 8) | 255);
	}
}

uint32_t	get_shifted_color(uint32_t rgba, float col_shift)
{
	return (get_rgba(get_r(rgba) + (int)col_shift, get_g(rgba) + (int)col_shift, get_b(rgba) + (int)col_shift, get_a(rgba)));
}

void	change_color_for_each_pixel(t_scroll_hook_param *shp)
{
	t_vector	iter;

	iter = (t_vector){0, 0};
	// printf("Hello/n");
	while (iter.x < ((long double)shp->img->width))
	{
		while (iter.y < ((long double)shp->img->height))
		{
			mlx_put_pixel(shp->img, iter.x, iter.y,
				mlx_get_pixel_color(shp->img, iter.x, iter.y));
			iter.y++;
		}
	iter.x++;
	iter.y = 0;
	}
}

void	shift_color(t_scroll_hook_param *shp, long double translation)
{
	shp->fractal.col_shift += translation;
	// change_color_for_each_pixel(shp);
	ft_draw_fractal2(shp->img, shp->fractal);
	return ;
}
