/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:28:22 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/23 20:25:51 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

// int	mandelbrot(t_complex c)
// {
// 	t_complex	z;
// 	t_complex	res;
// 	int			iterations;

// 	z.real = 0;
// 	z.imaginary = 0;
// 	iterations = 0;

// 	while (iterations++ < ITER)
// 	{
// 		if (ft_squared_absolute_complex(z) > 4)
// 			return (iterations);
// 		ft_multiply_complex(&z, &z, &res);
// 		ft_add_complex(&res, &c, &z);
// 	}
// 	return (0);
// }

int	mandelbrot_eq(t_complex c, int julia, t_complex constant)
{
	t_complex	z;
	t_complex	res;
	int			iterations;

	if (julia > 0)
	{
		z = c;
		c = constant;
	}
	else
	{
		z.real = 0;
		z.imaginary = 0;
	}
	iterations = 0;
	while (iterations++ < ITER)
	{
		if (ft_squared_absolute_complex(z) > 4)
			return (iterations);
		ft_multiply_complex(&z, &z, &res);
		ft_add_complex(&res, &c, &z);
	}
	return (0);
}

int	julia(t_complex z)
{
	t_complex	c;
	t_complex	res;
	int			iterations;

	c.real = 0;
	c.imaginary = 0;
	iterations = 0;

	while (iterations++ < ITER)
	{
		if (ft_squared_absolute_complex(z) > 4)
			return (iterations);
		ft_multiply_complex(&z, &z, &res);
		ft_add_complex(&res, &c, &z);
	}
	return (0);
}

//z_{0} = 0;
//z_{n+1} = z_{n}^{2}+c
