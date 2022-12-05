/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:20:13 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/05 09:27:16 by sdukic           ###   ########.fr       */
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

static int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	check_main_param(int argc, char *argv[])
{
	int	correct;

	correct = (argc != 1 && argc != 3 && argc <= 4
			&& (!ft_strcmp(argv[1], "mandelbrot")
				|| !ft_strcmp(argv[1], "julia")
				|| !ft_strcmp(argv[1], "mandelbrot3")
				|| !ft_strcmp(argv[1], "eye")
				|| !ft_strcmp(argv[1], "mandelbrot4")));
	if (argc == 4)
		if (!is_all_digit(argv[2]) || !is_all_digit(argv[3]))
			correct = 0;
	if (!correct)
		ft_printf("Usage: ./fract_ol <name> <num> <num>\n");
	return (correct);
}
