/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:02:47 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/23 19:15:05 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_sinus_colors(int iterations)
{
	if (iterations == 0)
		return (255);
	else
	{
		return (
			get_rgba((int)((sin(iterations * 0.8 + 3.0) + 1.0) / 2.0 * 255.0)
			, (int)((sin(iterations * 0.5 + 4.0) + 1.0) / 2.0 * 255.0)
			, (int)((sin(iterations * 0.3 + 1.0) + 1.0) / 2.0 * 255.0)
			, 255));
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
