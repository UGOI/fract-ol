/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_pixel_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:47:54 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/26 22:12:18 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

uint32_t	mlx_get_pixel_color(mlx_image_t *image, uint32_t x, uint32_t y)
{
	// MLX_NONNULL(image);
	// MLX_ASSERT(x < image->width, "Pixel is out of bounds");
	// MLX_ASSERT(y < image->height, "Pixel is out of bounds");

	uint8_t* pixelstart = &image->pixels[(y * image->width + x) * sizeof(int32_t)];

	uint32_t color = get_rgba(*(pixelstart), *(pixelstart + 1), *(pixelstart + 2), *(pixelstart + 3));
	return (color);
}
