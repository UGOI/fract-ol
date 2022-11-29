/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:28:50 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/29 14:09:41 by sdukic           ###   ########.fr       */
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

void	shift_fract_coord(t_fractal *fractal, t_vector coordinate_translation)
{
	fractal->top_left.x += coordinate_translation.x;
	fractal->bottom_left.x += coordinate_translation.x;
	fractal->top_right.x += coordinate_translation.x;
	fractal->top_left.y += coordinate_translation.y;
	fractal->bottom_left.y += coordinate_translation.y;
	fractal->top_right.y += coordinate_translation.y;
}

void	put_trans_fract(mlx_image_t *img, t_vector iter, uint32_t pix_trans)
{
	int			iterations;
	uint32_t	color;

	color = mlx_get_pixel_color(img, iter.x, iter.y);
	mlx_put_pixel(img, iter.x - pix_trans, iter.y,
		color);
	// printf("%Lf\n", iter.x);
}

void	put_trans_fract2(mlx_image_t *img, t_vector iter, t_vector_uint_32_t pix_trans)
{
	int			iterations;
	uint32_t	color;

	color = mlx_get_pixel_color(img, iter.x, iter.y);
	mlx_put_pixel(img, iter.x - pix_trans.x, iter.y - pix_trans.y,
		color);
}

t_fractal	get_right_fract_sect(t_fractal fract, long double cord_trans)
{
	t_fractal	fract_sect;

	fract_sect = fract;
	fract_sect.top_left.x = fract_sect.top_right.x - cord_trans;
	fract_sect.bottom_left.x = fract_sect.top_right.x - cord_trans;
	return (fract_sect);
}

t_fractal	get_left_fract_sect(t_fractal fract, long double cord_trans)
{
	t_fractal	fract_sect;

	fract_sect = fract;
	fract_sect.top_right.x = fract_sect.top_left.x + cord_trans;
	return (fract_sect);
}

t_fractal	get_bottom_fract_sect(t_fractal fract, long double cord_trans)
{
	t_fractal	fract_sect;

	fract_sect = fract;
	fract_sect.top_left.y = fract_sect.bottom_left.y + cord_trans;
	fract_sect.top_right.y = fract_sect.bottom_left.y + cord_trans;
	return (fract_sect);
}

t_fractal	create_top_fract(t_fractal fract, long double cord_trans)
{
	t_fractal	fract_sect;

	fract_sect = fract;
	fract_sect.bottom_left.y = fract.top_left.y - cord_trans;
	return (fract_sect);
}

t_frame	get_right_frame_sect(mlx_image_t *img, long double pix_trans, t_fractal *fract)
{
	t_frame	frame_sect;

	frame_sect.top_left.x = img->width - pix_trans - 1;
	frame_sect.top_left.y = 0;
	frame_sect.width = pix_trans;
	frame_sect.height = img->height - 1;

	fract->frame.top_left.x = img->width - pix_trans - 1;
	fract->frame.top_left.y = 0;
	fract->frame.width = pix_trans;
	fract->frame.height = img->height - 1;
	return (frame_sect);
}

t_frame	get_left_frame_sect(mlx_image_t *img, long double pix_trans, t_fractal *fract)
{
	t_frame	frame_sect;

	frame_sect.top_left.x = 0;
	frame_sect.top_left.y = 0;
	frame_sect.width = pix_trans;
	frame_sect.height = img->height - 1;

	fract->frame.top_left.x = 0;
	fract->frame.top_left.y = 0;
	fract->frame.width = pix_trans;
	fract->frame.height = img->height - 1;
	return (frame_sect);
}

t_frame	get_bottom_frame_sect(mlx_image_t *img, long double pix_trans, t_fractal *fract)
{
	t_frame	frame_sect;

	frame_sect.top_left.x = 0;
	frame_sect.top_left.y = img->height - pix_trans - 1;
	frame_sect.width = img->width - 1;
	frame_sect.height = pix_trans;

	fract->frame.top_left.x = 0;
	fract->frame.top_left.y = img->height - pix_trans - 1;
	fract->frame.width = img->width - 1;
	fract->frame.height = pix_trans;

	// printf("%Lf, %Lf, %d, %d", frame_sect.top_left.x, frame_sect.top_left.y, frame_sect.width, frame_sect.height);
	return (frame_sect);
}

t_frame	set_top_frame_sect(mlx_image_t *img, long double pix_trans, t_fractal *fract)
{
	t_frame	frame_sect;

	frame_sect.top_left.x = 0;
	frame_sect.top_left.y = 0;
	frame_sect.width = img->width - 1;
	frame_sect.height = pix_trans;

	// printf("%Lf, %Lf, %d, %d", frame_sect.top_left.x, frame_sect.top_left.y, frame_sect.width, frame_sect.height);

	fract->frame.top_left.x = 0;
	fract->frame.top_left.y = 0;
	fract->frame.width = img->width - 1;
	fract->frame.height = pix_trans;
	return (frame_sect);
}

void	trans_fract_left(t_scroll_hook_param *shp,
t_vector_uint_32_t pix_trans)
{
	t_vector	iter;
	long double	cord_trans;

	cord_trans = (long double)pix_trans.x / (long double)shp->img->width
		* ft_get_fractal_dimensions(shp->fractal).x;
	iter = (t_vector){(long double)pix_trans.x, 0};
	while (iter.x < ((long double)shp->img->width))
	{
		while (iter.y < ((long double)shp->img->height))
		{
			// put_trans_fract(shp->img, iter, pix_trans);
			put_trans_fract2(shp->img, iter, pix_trans);
			iter.y++;
		}
	iter.x++;
	iter.y = 0;
	}
	shift_fract_coord(&(shp->fractal), (t_vector){cord_trans, 0});
	get_right_frame_sect(shp->img, pix_trans.x, &shp->fractal);
	ft_draw_fractal2(shp->img, get_right_fract_sect(shp->fractal, cord_trans));
}

void	trans_fract_right(t_scroll_hook_param *shp,
t_vector_uint_32_t pix_trans)
{
	t_vector	iter;
	long double	cord_trans;

	cord_trans = (long double)pix_trans.x / (long double)shp->img->width
		* ft_get_fractal_dimensions(shp->fractal).x;
	iter = (t_vector){shp->img->width - (long double)pix_trans.x - 1, 0};
	while (iter.x >= 0)
	{
		while (iter.y < ((long double)shp->img->height))
		{
			// put_trans_fract(shp->img, iter, -pix_trans);
			put_trans_fract2(shp->img, iter, (t_vector_uint_32_t){-pix_trans.x, pix_trans.y});
			iter.y++;
		}
	iter.x--;
	iter.y = 0;
	}
	shift_fract_coord(&(shp->fractal), (t_vector){-cord_trans, 0});
	get_left_frame_sect(shp->img, pix_trans.x, &shp->fractal);
	ft_draw_fractal2(shp->img, get_left_fract_sect(shp->fractal, cord_trans));
}

void	trans_fract_up(t_scroll_hook_param *shp,
t_vector_uint_32_t pix_trans)
{
	t_vector	iter;
	long double	cord_trans;

	cord_trans = (long double)pix_trans.y / (long double)shp->img->height
		* ft_get_fractal_dimensions(shp->fractal).y;
	iter = (t_vector){0, (long double)pix_trans.y};
	while (iter.y < ((long double)shp->img->height))
	{
		while (iter.x < ((long double)shp->img->width))
		{
			put_trans_fract2(shp->img, iter, (t_vector_uint_32_t){pix_trans.x, pix_trans.y});
			iter.x++;
		}
	iter.y++;
	iter.x = 0;
	}
	shift_fract_coord(&(shp->fractal), (t_vector){0, -cord_trans});
	get_bottom_frame_sect(shp->img, pix_trans.y, &shp->fractal);
	ft_draw_fractal2(shp->img, get_bottom_fract_sect(shp->fractal, cord_trans));
}

void	trans_fract_down(t_scroll_hook_param *shp,
t_vector_uint_32_t pix_trans)
{
	t_vector	iter;
	long double	cord_trans;

	cord_trans = (long double)pix_trans.y / (long double)shp->img->height
		* ft_get_fractal_dimensions(shp->fractal).y;
	iter = (t_vector){0, shp->img->height - 1 - (long double)pix_trans.y};
	while (iter.y >= 0)
	{
		while (iter.x < ((long double)shp->img->width))
		{
			put_trans_fract2(shp->img, iter, (t_vector_uint_32_t){pix_trans.x, -pix_trans.y});
			iter.x++;
		}
	iter.y--;
	iter.x = 0;
	}
	shift_fract_coord(&(shp->fractal), (t_vector){0, cord_trans});
	set_top_frame_sect(shp->img, pix_trans.y, &shp->fractal);
	ft_draw_fractal2(shp->img, create_top_fract(shp->fractal, cord_trans));
}
