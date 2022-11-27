/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:28:50 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/27 18:38:00 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"
#include "MLX42/MLX42.h"
#include <stdio.h>

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

// void	translate_fractal_horizontal_optimized(t_scroll_hook_param *shp,
// long double translation)
// {
// 	t_fractal temp;
// 	uint32_t color;
// 	long double	fract_width;

// 	fract_width = shp->fractal.top_right.x - shp->fractal.top_left.x;
// 	temp = shp->fractal;
// 	shp->img->instances[0].x += translation / fract_width * shp->img->width;

// 	color =	mlx_get_pixel_color(shp->img, 0, 0);
// 	printf("%d\n", color);
// }

void	translate_fractal_horizontal_optimized(t_scroll_hook_param *shp,
uint32_t pixel_translation)
{
	t_vector	iter;
	long double	coordinate_translation;
	uint32_t	color;
	long double	fract_width;
	t_fractal	temp;
	t_frame 	frame;

	fract_width = shp->fractal.top_right.x - shp->fractal.top_left.x;
	coordinate_translation = (long double)pixel_translation * fract_width / (long double)shp->img->width;

	iter = (t_vector){(long double)pixel_translation, 0};
	while (iter.x < ((long double)shp->img->width - 1))
	{
		while (iter.y < ((long double)shp->img->height - 1))
		{
			color =	mlx_get_pixel_color(shp->img, iter.x, iter.y);
			mlx_put_pixel(shp->img, iter.x - pixel_translation, iter.y,
				color);
			iter.y++;
		}
	iter.x++;
	iter.y = 0;
	}


	shp->fractal.top_left.x += coordinate_translation;
	shp->fractal.bottom_left.x += coordinate_translation;
	shp->fractal.top_right.x += coordinate_translation;

	temp = shp->fractal;
	temp.top_left.x = temp.top_right.x - coordinate_translation;
	temp.bottom_left.x = temp.top_right.x - coordinate_translation;

	frame.top_left.x = shp->img->width - pixel_translation - 1;
	frame.top_left.y = 0;
	frame.width = pixel_translation + 1;
	frame.height = shp->img->height;
	// printf("%Lf, %Lf, %d, %d\n", frame.top_left.x, frame.top_left.y, frame.width, frame.height);
	// printf("%Lf, %Lf, %Lf, %Lf, %Lf, %Lf\n", temp.top_left.x, temp.top_left.y, temp.top_right.x, temp.top_right.y, temp.bottom_left.x, temp.bottom_left.y);
	ft_draw_fractal2(shp->img, temp, frame);

}
