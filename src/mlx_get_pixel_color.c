/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_pixel_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:47:54 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/30 21:12:14 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

uint32_t	mlx_get_pixel_color(mlx_image_t *image, uint32_t x, uint32_t y)
{
	uint8_t		*pixelstart;
	uint32_t	color;

	pixelstart = &image->pixels[(y * image->width + x) * sizeof(int32_t)];
	color = get_rgba(*(pixelstart), *(pixelstart + 1),
			*(pixelstart + 2), *(pixelstart + 3));
	return (color);
}
