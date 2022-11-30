/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:28:50 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/30 21:16:45 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"
#include "MLX42/MLX42.h"
#include <stdio.h>
#include<math.h>
#include "../lib/libft/libft.h"
#include "../lib/libft/ft_printf.h"
#include <stdlib.h>

void	trans_fract_left(t_scroll_hook_param *shp,
t_vector pix_trans)
{
	t_vector	iter;
	long double	cord_trans;
	t_fractal	temp_fract;

	cord_trans = pix_trans.x / (long double)shp->img->width
		* shp->fractal.dim.x;
	iter = (t_vector){pix_trans.x, 0};
	while (iter.x < ((long double)shp->img->width))
	{
		while (iter.y < ((long double)shp->img->height))
		{
			put_trans_fract(shp->img, iter, pix_trans);
			iter.y++;
		}
	iter.x++;
	iter.y = 0;
	}
	shift_fract_coord(&(shp->fractal), (t_vector){cord_trans, 0});
	temp_fract = shp->fractal;
	set_frame(shp->img, (t_vector){-pix_trans.x, 0}, &temp_fract);
	ft_draw_fractal2(shp->img, get_fract_sect(temp_fract,
			(t_vector){-cord_trans, 0}));
}

void	trans_fract_right(t_scroll_hook_param *shp,
t_vector pix_trans)
{
	t_vector	iter;
	long double	cord_trans;
	t_fractal	temp_fract;

	cord_trans = pix_trans.x / (long double)shp->img->width
		* shp->fractal.dim.x;
	iter = (t_vector){shp->img->width - pix_trans.x - 1, 0};
	while (iter.x >= 0)
	{
		while (iter.y < ((long double)shp->img->height))
		{
			put_trans_fract(shp->img, iter,
				(t_vector){-pix_trans.x, pix_trans.y});
			iter.y++;
		}
	iter.x--;
	iter.y = 0;
	}
	shift_fract_coord(&(shp->fractal), (t_vector){-cord_trans, 0});
	temp_fract = shp->fractal;
	set_frame(shp->img, (t_vector){(long double)pix_trans.x, 0}, &temp_fract);
	ft_draw_fractal2(shp->img, get_fract_sect(temp_fract,
			(t_vector){cord_trans, 0}));
}

void	trans_fract_up(t_scroll_hook_param *shp,
t_vector pix_trans)
{
	t_vector	iter;
	long double	cord_trans;
	t_fractal	temp_fract;

	cord_trans = pix_trans.y / (long double)shp->img->height
		* shp->fractal.dim.y;
	iter = (t_vector){0, pix_trans.y};
	while (iter.y < ((long double)shp->img->height))
	{
		while (iter.x < ((long double)shp->img->width))
		{
			put_trans_fract(shp->img, iter,
				(t_vector){pix_trans.x, pix_trans.y});
			iter.x++;
		}
	iter.y++;
	iter.x = 0;
	}
	shift_fract_coord(&(shp->fractal), (t_vector){0, -cord_trans});
	temp_fract = shp->fractal;
	set_frame(shp->img, (t_vector){0, pix_trans.y}, &temp_fract);
	ft_draw_fractal2(shp->img, get_fract_sect(temp_fract,
			(t_vector){0, cord_trans}));
}

void	trans_fract_down(t_scroll_hook_param *shp,
t_vector pix_trans)
{
	t_vector	iter;
	long double	cord_trans;
	t_fractal	temp_fract;

	cord_trans = pix_trans.y / (long double)shp->img->height
		* shp->fractal.dim.y;
	iter = (t_vector){0, shp->img->height - 1 - pix_trans.y};
	while (iter.y >= 0)
	{
		while (iter.x < ((long double)shp->img->width))
		{
			put_trans_fract(shp->img, iter, (t_vector)
			{pix_trans.x, -pix_trans.y});
			iter.x++;
		}
	iter.y--;
	iter.x = 0;
	}
	shift_fract_coord(&(shp->fractal), (t_vector){0, cord_trans});
	temp_fract = shp->fractal;
	set_frame(shp->img, (t_vector){0, -pix_trans.y}, &temp_fract);
	ft_draw_fractal2(shp->img, get_fract_sect(temp_fract,
			(t_vector){0, -cord_trans}));
}
