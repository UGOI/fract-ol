/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:21:46 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/25 16:47:06 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"
#include <math.h>

t_complex	ft_add_complex(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.real = c1.real + c2.real;
	res.imaginary = c1.imaginary + c2.imaginary;
	return (res);
}

t_complex	ft_subtract_complex(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.real = c1.real - c2.real;
	res.imaginary = c1.imaginary - c2.imaginary;
	return (res);
}

t_complex	ft_multiply_complex(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.real = (c1.real) * (c2.real) - (c1.imaginary) * (c2.imaginary);
	res.imaginary = (c1.real) * (c2.imaginary) + (c1.imaginary) * (c2.real);
	return (res);
}

t_complex	ft_power_complex(t_complex c1, long double pow)
{
	t_complex	res;

	res.real = 1;
	res.imaginary = 0;
	while (pow--)
	{
		res = ft_multiply_complex(res, c1);
	}
	return (res);
}
