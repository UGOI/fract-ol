/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:04:16 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/30 13:52:35 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <memory.h>
#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"
#include "../lib/libft/libft.h"
#include "../lib/libft/ft_printf.h"

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_vector			zoom_point;
	int32_t				x;
	int32_t				y;
	t_scroll_hook_param	*shp;

	(void)xdelta;
	(void)ydelta;
	shp = param;
	mlx_get_mouse_pos(shp->mlx, &x, &y);
	zoom_point.x = (long double)x;
	zoom_point.y = (long double)y;
	if (ydelta > 0)
		ft_zoom(zoom_point, 1, shp);
	else if (ydelta < 0)
		ft_zoom(zoom_point, -1, shp);
}

void	my_resizehook(int32_t width, int32_t height, void *param)
{
	t_scroll_hook_param	*shp;

	shp = param;
	mlx_resize_image(shp->img, width, height);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_scroll_hook_param	*shp;
	long double			translation;

	shp = param;
	translation = 0.1 * (shp->fractal.dim.x);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit_safely(shp);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		shift_color(shp, 0.1);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		shift_color(shp, -0.1);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		trans_fract_left(shp, (t_vector_uint_32_t){10, 0});
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		trans_fract_right(shp, (t_vector_uint_32_t){10, 0});
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		trans_fract_up(shp, (t_vector_uint_32_t){0, 10});
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		trans_fract_down(shp, (t_vector_uint_32_t){0, 10});
}
