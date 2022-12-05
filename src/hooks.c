/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:04:16 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/05 12:42:16 by sdukic           ###   ########.fr       */
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

void	exit_safely(t_scroll_hook_param *shp)
{
	mlx_delete_image(shp->mlx, shp->img);
	mlx_terminate(shp->mlx);
	ft_printf("\nExited safely!!!\n");
	exit(1);
	return ;
}

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
	t_resize_hook_param	*rhp;

	rhp = param;
	(void)height;
	(void)width;
	mlx_delete_image(rhp->shp->mlx, rhp->shp->img);
	set_fractal_dim(&(rhp->shp->fractal), (t_vector){rhp->shp->fractal.dim.x,
		rhp->shp->fractal.dim.x
		/ (long double)width * (long double)height});
	set_fractal_frame(&(rhp->shp->fractal),
		(t_frame){(long double)width - 1, (long double)height - 1,
		(t_vector){0, 0}});
	rhp->shp->img = mlx_new_image(rhp->shp->mlx, width, height);
	ft_draw_fractal2(rhp->shp->img, (rhp->shp->fractal));
	if (mlx_image_to_window(rhp->shp->mlx, rhp->shp->img, 0, 0) < 0)
		error();
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
		trans_fract_left(shp, (t_vector){10, 0});
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		trans_fract_right(shp, (t_vector){10, 0});
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		trans_fract_up(shp, (t_vector){0, 10});
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		trans_fract_down(shp, (t_vector){0, 10});
}
