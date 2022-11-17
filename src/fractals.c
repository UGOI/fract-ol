/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:28:22 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/17 16:04:54 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	mandelbrot(t_complex c)
{
	t_complex	z;
	int			iterations;

	z.real = 0;
	z.imaginary = 0;
	iterations = 0;

	printf("Initial:	%.3f %+.3fi\n\n", c.real, c.imaginary);
	while (iterations++ < 30)
	{
		if (ft_squared_absolute_complex(z) > 4)
			return (iterations);
		printf("Before mult:	%.3f %+.3fi\n\n", z.real, z.imaginary);
		ft_multiply_complex(&z, &z);
		printf("Before add add:	%.3f %+.3fi\n\n", z.real, z.imaginary);
		ft_add_complex(&z, &c);
	}
	return (0);
}

//z_{0} = 0;
//z_{n+1} = z_{n}^{2}+c
