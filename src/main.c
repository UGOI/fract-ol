/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:29:06 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/23 22:02:48 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Written by Bruh

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <memory.h>
#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"
#define WIDTH 5120
#define HEIGHT 2880

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_erase_img_content(mlx_image_t *img)
{
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
}

void	ft_draw_fractal(mlx_image_t *img, t_fractal fractal)
{
	t_vector	function_dimensions;
	t_vector	iter;
	t_complex	c;
	t_vector	steps;
	int			iterations;

	ft_erase_img_content(img);
	function_dimensions.x = fractal.top_right.x - fractal.top_left.x;
	function_dimensions.y = fractal.top_left.y - fractal.bottom_left.y;
	steps.x = function_dimensions.x / (long double)img->width;
	steps.y = function_dimensions.y / (long double)img->height;
	// printf("\n%u, %u\n",get_rgba(255, 255, 255, 255), (RGB_MAX << 8) | 255);
	while (iter.x < ((long double)img->width - 1))
	{
		c.real = fractal.top_left.x + steps.x * (long double)iter.x;
		while (iter.y < ((long double)img->height - 1))
		{
			c.imaginary = fractal.top_left.y - steps.y * (long double)iter.y;
			iterations = mandelbrot_eq(c, fractal.julia, (t_complex){0.5, 0.5});
			mlx_put_pixel(img, iter.x, iter.y, ft_sinus_colors(iterations));
			iter.y++;
		}
	iter.x++;
	iter.y = 0;
	}
}

void	my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_vector		zoom_point;
	int32_t			x;
	int32_t			y;
	t_scroll_hook_param *scroll_hook_param;

	scroll_hook_param = param;
	mlx_get_mouse_pos(scroll_hook_param->mlx, &x, &y);
	zoom_point.x = (long double)x;
	zoom_point.y = (long double)y;
	if (ydelta > 0)
		ft_zoom(zoom_point, scroll_hook_param->img, 1, scroll_hook_param->fractal);
	else if (ydelta < 0)
		ft_zoom(zoom_point, scroll_hook_param->img, -1, scroll_hook_param->fractal);
}

int32_t	main(int argc, char* argv[])
{
	t_fractal			fractal;
	t_scroll_hook_param scroll_hook_param;

	if (!strcmp(argv[1], "julia"))
	{
		ft_initialize_julia(&fractal);
		fractal.constant.real = 0;
		fractal.constant.imaginary = 0;
		scroll_hook_param.fractal = fractal;
	}
	else
	{
		ft_initialize_mandelbrot(&fractal);
		scroll_hook_param.fractal = fractal;
	}
	scroll_hook_param.mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!scroll_hook_param.mlx)
		error();
	scroll_hook_param.img = mlx_new_image(scroll_hook_param.mlx, 500, 500);
	if (!scroll_hook_param.img)
		error();
	mlx_scroll_hook(scroll_hook_param.mlx, &my_scrollhook, &scroll_hook_param);
	ft_draw_fractal(scroll_hook_param.img, fractal);
	if (mlx_image_to_window(scroll_hook_param.mlx, scroll_hook_param.img, 0, 0) < 0)
		error();
	mlx_loop(scroll_hook_param.mlx);
	mlx_delete_image(scroll_hook_param.mlx, scroll_hook_param.img);
	mlx_terminate(scroll_hook_param.mlx);
	return (EXIT_SUCCESS);
}
