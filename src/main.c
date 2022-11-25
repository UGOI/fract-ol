/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:29:06 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/26 00:34:46 by sdukic           ###   ########.fr       */
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
#define WIDTH 500
#define HEIGHT 500

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	exit_safely(t_scroll_hook_param *shp)
{
	mlx_delete_image(shp->mlx, shp->img);
	mlx_terminate(shp->mlx);
	ft_printf("\nExited safely!!!\n");
	exit(1);
	return ;
}

int	check_main_param(int argc, char *argv[])
{
	int	correct;

	correct = (argc != 3 && argc <= 4 && (!ft_strcmp(argv[1], "mandelbrot")
				|| !ft_strcmp(argv[1], "julia")
				|| !ft_strcmp(argv[1], "mandelbrot3")
				|| !ft_strcmp(argv[1], "mandelbrot4")));
	if (!correct)
		ft_printf("Usage: ./fract_ol <name> <num> <num>\n");
	return (correct);
}

t_complex	get_c_from_args(int argc, char *argv[])
{
	t_complex	c;

	if (argc == 2)
		c = (t_complex){-0.8, 0.156};
	else
		c = (t_complex){(long double)ft_atof(argv[2]),
			(long double)ft_atof(argv[3])};
	return (c);
}

int32_t	main(int argc, char *argv[])
{
	t_scroll_hook_param	shp;

	if (!check_main_param(argc, argv))
		return (0);
	ft_initialize_fractal(&(shp.fractal), argv[1], get_c_from_args(argc, argv));
	shp.mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!shp.mlx)
		error();
	shp.img = mlx_new_image(shp.mlx, WIDTH, HEIGHT);
	if (!shp.img)
		error();
	mlx_scroll_hook(shp.mlx, &my_scrollhook, &shp);
	mlx_key_hook(shp.mlx, &my_keyhook, &shp);
	ft_draw_fractal(shp.img, (shp.fractal));
	if (mlx_image_to_window(shp.mlx, shp.img, 0, 0) < 0)
		error();
	mlx_loop(shp.mlx);
	mlx_delete_image(shp.mlx, shp.img);
	mlx_terminate(shp.mlx);
	return (EXIT_SUCCESS);
}
