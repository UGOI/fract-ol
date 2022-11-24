/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:29:06 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/24 11:55:25 by sdukic           ###   ########.fr       */
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
#define WIDTH 500
#define HEIGHT 500

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_vector			zoom_point;
	int32_t				x;
	int32_t				y;
	t_scroll_hook_param	*shp;

	shp = param;
	mlx_get_mouse_pos(shp->mlx, &x, &y);
	zoom_point.x = (long double)x;
	zoom_point.y = (long double)y;
	if (ydelta > 0)
		ft_zoom(zoom_point, shp->img, 1, shp->fractal);
	else if (ydelta < 0)
		ft_zoom(zoom_point, shp->img, -1, shp->fractal);
}

int	check_main_param(int argc, char *argv[])
{
	int	correct;

	correct = (argc != 3 && argc <= 4 && (!strcmp(argv[1], "mandelbrot")
				|| !strcmp(argv[1], "julia") || !strcmp(argv[1], "mandelbrot3")
				|| !strcmp(argv[1], "mandelbrot4")));
	if (!correct)
		printf("Usage: ./fract_ol <name> <num> <num>\n");
	return (correct);
}

int32_t	main(int argc, char *argv[])
{
	t_scroll_hook_param	shp;
	t_complex			c;

	if (!check_main_param(argc, argv))
		return (0);
	if (argc == 2)
		c = (t_complex){0.0, 0.0};
	else
		c = (t_complex){(long double)atof(argv[2]), (long double)atof(argv[3])};
	ft_initialize_fractal(&(shp.fractal), argv[1], c);
	shp.mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!shp.mlx)
		error();
	shp.img = mlx_new_image(shp.mlx, 500, 500);
	if (!shp.img)
		error();
	mlx_scroll_hook(shp.mlx, &my_scrollhook, &shp);
	ft_draw_fractal(shp.img, (shp.fractal));
	if (mlx_image_to_window(shp.mlx, shp.img, 0, 0) < 0)
		error();
	mlx_loop(shp.mlx);
	mlx_delete_image(shp.mlx, shp.img);
	mlx_terminate(shp.mlx);
	return (EXIT_SUCCESS);
}

// int32_t	main(void)
// {
// 	t_complex c1 = {2, 6};
// 	t_complex c2 = {-2, 9};
// 	t_complex res;

// 	res = ft_divide_complex(c1, c2);

// 	printf("%Lf %+Lfi\n", res.real, res.imaginary);
// }
