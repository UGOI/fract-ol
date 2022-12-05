/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:47:29 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/30 21:17:35 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"
#include "MLX42/MLX42.h"
#include <stdio.h>
#include<math.h>
#include "../lib/libft/libft.h"
#include "../lib/libft/ft_printf.h"
#include <stdlib.h>

void	shift_fract_coord(t_fractal *fractal, t_vector coordinate_translation)
{
	set_fractal_top_left(fractal,
		add_vector(fractal->top_left, coordinate_translation));
}

void	put_trans_fract(mlx_image_t *img,
	t_vector iter, t_vector pix_trans)
{
	mlx_put_pixel(img, iter.x - pix_trans.x, iter.y - pix_trans.y,
		mlx_get_pixel_color(img, iter.x, iter.y));
}

t_fractal	get_fract_sect(t_fractal fract, t_vector cord_trans)
{
	t_fractal	fract_sect;

	if ((cord_trans.x != 0 && cord_trans.y != 0)
		|| (cord_trans.x == 0 && cord_trans.y == 0))
		exit(1);
	fract_sect = fract;
	if (cord_trans.x < 0)
	{
		fract_sect.top_left.x = fract_sect.top_left.x
			+ fract_sect.dim.x + cord_trans.x;
		fract_sect.dim.x = -cord_trans.x;
	}
	else if (cord_trans.x > 0)
		fract_sect.dim.x = cord_trans.x;
	if (cord_trans.y > 0)
	{
		fract_sect.top_left.y = fract_sect.top_left.y
			- fract_sect.dim.y + cord_trans.y;
		fract_sect.dim.y = cord_trans.y;
	}
	else if (cord_trans.y < 0)
		fract_sect.dim.y = -cord_trans.y;
	return (fract_sect);
}

void	set_frame(mlx_image_t *img, t_vector pix_trans, t_fractal *fract)
{
	if (pix_trans.x != 0)
	{
		if (pix_trans.x < 0)
			fract->frame.top_left.x = img->width + pix_trans.x - 1;
		else if (pix_trans.x > 0)
			fract->frame.top_left.x = 0;
		fract->frame.top_left.y = 0;
		fract->frame.width = fabsl(pix_trans.x);
		fract->frame.height = img->height - 1;
	}
	else if (pix_trans.y != 0)
	{
		fract->frame.top_left.x = 0;
		if (pix_trans.y < 0)
			fract->frame.top_left.y = 0;
		else if (pix_trans.y > 0)
			fract->frame.top_left.y = img->height - pix_trans.y - 1;
		fract->frame.width = img->width - 1;
		fract->frame.height = fabsl(pix_trans.y);
	}
	return ;
}
