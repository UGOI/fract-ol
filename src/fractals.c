/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:28:22 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/17 16:45:27 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	mandelbrot(t_complex c)
{
	t_complex	z;
	t_complex	res;
	int			iterations;

	z.real = 0;
	z.imaginary = 0;
	iterations = 0;

	while (iterations++ < 30)
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
