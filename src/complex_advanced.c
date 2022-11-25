/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_advanced.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:21:46 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/25 16:40:29 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

t_complex	ft_divide_complex(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.real = ((c1.real) * (c2.real) + (c1.imaginary) * (c2.imaginary))
		/ (powl((c2.real), 2) + powl((c2.imaginary), 2));
	res.imaginary = ((c1.imaginary) * (c2.real) - (c1.real) * (c2.imaginary))
		/ (powl((c2.real), 2) + powl((c2.imaginary), 2));
	return (res);
}

long double	ft_squared_absolute_complex(t_complex c)
{
	long double	squared_abolute;

	squared_abolute = powl(c.real, 2) + powl(c.imaginary, 2);
	return (squared_abolute);
}
