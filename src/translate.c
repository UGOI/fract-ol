/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:28:50 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/30 13:52:48 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"
#include "MLX42/MLX42.h"
#include <stdio.h>

void	shift_fract_coord(t_fractal *fractal, t_vector coordinate_translation)
{
	set_fractal_top_left(fractal, add_vector(fractal->top_left, coordinate_translation));
}

void	put_trans_fract(mlx_image_t *img, t_vector iter, t_vector_uint_32_t pix_trans)
{
	mlx_put_pixel(img, iter.x - pix_trans.x, iter.y - pix_trans.y,
		mlx_get_pixel_color(img, iter.x, iter.y));
}

t_fractal	get_right_fract_sect(t_fractal fract, long double cord_trans)
{
	t_fractal	fract_sect;

	fract_sect = fract;
	fract_sect.top_left.x = fract_sect.top_left.x + fract_sect.dim.x - cord_trans;
	fract_sect.dim.x = cord_trans;
	return (fract_sect);
}

t_fractal	get_left_fract_sect(t_fractal fract, long double cord_trans)
{
	t_fractal	fract_sect;

	fract_sect = fract;
	fract_sect.dim.x = cord_trans;
	return (fract_sect);
}

t_fractal	get_bottom_fract_sect(t_fractal fract, long double cord_trans)
{
	t_fractal	fract_sect;

	fract_sect = fract;
	fract_sect.top_left.y = fract_sect.top_left.y - fract_sect.dim.y + cord_trans;
	fract_sect.dim.y = cord_trans;
	return (fract_sect);
}

t_fractal	create_top_fract(t_fractal fract, long double cord_trans)
{
	t_fractal	fract_sect;

	fract_sect = fract;
	fract_sect.dim.y = cord_trans;
	return (fract_sect);
}

void	set_right_frame(mlx_image_t *img, long double pix_trans, t_fractal *fract)
{
	fract->frame.top_left.x = img->width - pix_trans - 1;
	fract->frame.top_left.y = 0;
	fract->frame.width = pix_trans;
	fract->frame.height = img->height - 1;
	return ;
}

void	set_left_frame(mlx_image_t *img, long double pix_trans, t_fractal *fract)
{
	fract->frame.top_left.x = 0;
	fract->frame.top_left.y = 0;
	fract->frame.width = pix_trans;
	fract->frame.height = img->height - 1;
	return ;
}

void	set_bottom_frame(mlx_image_t *img, long double pix_trans, t_fractal *fract)
{
	fract->frame.top_left.x = 0;
	fract->frame.top_left.y = img->height - pix_trans - 1;
	fract->frame.width = img->width - 1;
	fract->frame.height = pix_trans;
	return ;
}

void set_top_frame(mlx_image_t *img, long double pix_trans, t_fractal *fract)
{
	fract->frame.top_left.x = 0;
	fract->frame.top_left.y = 0;
	fract->frame.width = img->width - 1;
	fract->frame.height = pix_trans;
	return ;
}

void	trans_fract_left(t_scroll_hook_param *shp,
t_vector_uint_32_t pix_trans)
{
	t_vector	iter;
	long double	cord_trans;

	cord_trans = (long double)pix_trans.x / (long double)shp->img->width
		* shp->fractal.dim.x;
	iter = (t_vector){(long double)pix_trans.x, 0};
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
	set_right_frame(shp->img, pix_trans.x, &shp->fractal);
	ft_draw_fractal2(shp->img, get_right_fract_sect(shp->fractal, cord_trans));
}

void	trans_fract_right(t_scroll_hook_param *shp,
t_vector_uint_32_t pix_trans)
{
	t_vector	iter;
	long double	cord_trans;

	cord_trans = (long double)pix_trans.x / (long double)shp->img->width
		* shp->fractal.dim.x;
	iter = (t_vector){shp->img->width - (long double)pix_trans.x - 1, 0};
	while (iter.x >= 0)
	{
		while (iter.y < ((long double)shp->img->height))
		{
			put_trans_fract(shp->img, iter, (t_vector_uint_32_t){-pix_trans.x, pix_trans.y});
			iter.y++;
		}
	iter.x--;
	iter.y = 0;
	}
	shift_fract_coord(&(shp->fractal), (t_vector){-cord_trans, 0});
	set_left_frame(shp->img, pix_trans.x, &shp->fractal);
	ft_draw_fractal2(shp->img, get_left_fract_sect(shp->fractal, cord_trans));
}

void	trans_fract_up(t_scroll_hook_param *shp,
t_vector_uint_32_t pix_trans)
{
	t_vector	iter;
	long double	cord_trans;

	cord_trans = (long double)pix_trans.y / (long double)shp->img->height
		* shp->fractal.dim.y;
	iter = (t_vector){0, (long double)pix_trans.y};
	while (iter.y < ((long double)shp->img->height))
	{
		while (iter.x < ((long double)shp->img->width))
		{
			put_trans_fract(shp->img, iter, (t_vector_uint_32_t){pix_trans.x, pix_trans.y});
			iter.x++;
		}
	iter.y++;
	iter.x = 0;
	}
	shift_fract_coord(&(shp->fractal), (t_vector){0, -cord_trans});
	set_bottom_frame(shp->img, pix_trans.y, &shp->fractal);
	ft_draw_fractal2(shp->img, get_bottom_fract_sect(shp->fractal, cord_trans));
}

void	trans_fract_down(t_scroll_hook_param *shp,
t_vector_uint_32_t pix_trans)
{
	t_vector	iter;
	long double	cord_trans;

	cord_trans = (long double)pix_trans.y / (long double)shp->img->height
		* shp->fractal.dim.y;
	iter = (t_vector){0, shp->img->height - 1 - (long double)pix_trans.y};
	while (iter.y >= 0)
	{
		while (iter.x < ((long double)shp->img->width))
		{
			put_trans_fract(shp->img, iter, (t_vector_uint_32_t){pix_trans.x, -pix_trans.y});
			iter.x++;
		}
	iter.y--;
	iter.x = 0;
	}
	shift_fract_coord(&(shp->fractal), (t_vector){0, cord_trans});
	set_top_frame(shp->img, pix_trans.y, &shp->fractal);
	ft_draw_fractal2(shp->img, create_top_fract(shp->fractal, cord_trans));
}
