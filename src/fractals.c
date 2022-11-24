/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:28:22 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/24 05:05:43 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	nova(t_complex c)
{
	t_complex	z;
	int			iterations;

	z.real = 0;
	z.imaginary = 0;
	iterations = 0;
	while (iterations++ < ITER)
	{
		// printf("\n%Lf, %Lf\n", z.real, z.imaginary);
		if (ft_squared_absolute_complex(z) > 4)
			return (iterations);
		// z = ft_add_complex(
		// 		ft_subtract_complex(
		// 			z,
		// 			ft_divide_complex(
		// 				ft_subtract_complex(ft_power_complex(z, 3), (t_complex){1, 0}),
		// 				ft_multiply_complex((t_complex){3,0}, ft_power_complex(z, 2))
		// 				)
		// 			),
		// 		c
		// 		);
		z = ft_multiply_complex(z, z);
		z = ft_add_complex(z, ft_divide_complex((t_complex){1,0}, c));
		// z = ft_divide_complex(
		// 		ft_power_complex(ft_subtract_complex(z, (t_complex){1, 0}), 3),
		// 		ft_multiply_complex((t_complex){3,0}, ft_power_complex(z, 2))
		// 		);
	}
	return (0);
}

int	mandelbrot3(t_complex c)
{
	t_complex	z;
	int			iterations;

	z.real = 0;
	z.imaginary = 0;
	iterations = 0;
	while (iterations++ < ITER)
	{
		if (ft_squared_absolute_complex(z) > 4)
			return (iterations);
		z = ft_power_complex(z, 3);
		z = ft_add_complex(z, c);
	}
	return (0);
}

int	mandelbrot4(t_complex c)
{
	t_complex	z;
	int			iterations;

	z.real = 0;
	z.imaginary = 0;
	iterations = 0;
	while (iterations++ < ITER)
	{
		if (ft_squared_absolute_complex(z) > 4)
			return (iterations);
		z = ft_power_complex(z, 6);
		z = ft_add_complex(z, c);
	}
	return (0);
}

int	eye(t_complex c)
{
	t_complex	z;
	int			iterations;

	z.real = 0;
	z.imaginary = 0;
	iterations = 0;
	while (iterations++ < ITER)
	{
		if (ft_squared_absolute_complex(z) > 4)
			return (iterations);
		z = ft_multiply_complex(z, z);
		z = ft_add_complex(z, ft_divide_complex((t_complex){1,0}, c));
	}
	return (0);
}

int	mandelbrot(t_complex c)
{
	t_complex	z;
	int			iterations;


	z.real = 0;
	z.imaginary = 0;
	iterations = 0;
	while (iterations++ < ITER)
	{
		if (ft_squared_absolute_complex(z) > 4)
			return (iterations);
		z = ft_multiply_complex(z, z);
		z = ft_add_complex(z, c);
	}
	return (0);
}

int	julia(t_complex z, t_complex c)
{
	int			iterations;

	iterations = 0;

	while (iterations++ < ITER)
	{
		if (ft_squared_absolute_complex(z) > 4)
			return (iterations);
		z = ft_multiply_complex(z, z);
		z = ft_add_complex(z, c);
	}
	return (0);
}


//z_{0} = 0;
//z_{n+1} = z_{n}^{2}+c
