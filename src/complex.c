/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:21:46 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/16 23:53:30 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

t_complex	*ft_add_complex(t_complex *c1, t_complex *c2)
{
	c1->real = c1->real + c2->real;
	c1->imaginary = c1->imaginary + c2->imaginary;
	return (c1);
}

t_complex	*ft_subtract_complex(t_complex *c1, t_complex *c2)
{
	c1->real = c1->real - c2->real;
	c1->imaginary = c1->imaginary - c2->imaginary;
	return (c1);
}

t_complex	*ft_multiply_complex(t_complex *c1, t_complex *c2)
{
	t_complex	temp;

	temp.real = c1->real;
	c1->real = (c1->real) * (c2->real) - (c1->imaginary) * (c2->imaginary);
	c1->imaginary = (temp.real) * (c2->imaginary) + (c1->imaginary) * (c2->real);
	return (c1);
}

t_complex	*ft_divide_complex(t_complex *c1, t_complex *c2)
{
	t_complex	temp;

	temp.real = c1->real;
	c1->real = ((c1->real) * (c2->real) + (c1->imaginary) * (c2->imaginary)) / (powf((c2->real),2) + powf((c2->imaginary),2));
	c1->imaginary = ((c1->imaginary) * (c2->real) - (temp.real) * (c2->imaginary)) / (powf((c2->real),2) + powf((c2->imaginary),2));
	return (c1);
}


/*
Multiplication of two complex numbers:
((c1->real) + (c1->imaginary)i)((c2->real) + (c2->imaginary)i)
= (c1->real)(c2->real) + i(c1->real)(c2->imaginary) + i(c1->imaginary)(c2->real) - (c1->imaginary)(c2->imaginary)
= (c1->real)(c2->real) - (c1->imaginary)(c2->imaginary) + i((c1->real)(c2->imaginary) + (c1->imaginary)(c2->real))

Division of two complex numbers:
((c1->real)+(c1->imaginary)*i)/((c2->real)+(c2->imaginary)*i)
= ((c1->real)(c2->real)+(c1->imaginary)(c2->imaginary))/(powf((c2->real),2)+powf((c2->imaginary),2))+i((c1->imaginary)(c2->real)-(c1->real)(c2->imaginary))/(powf((c2->real),2)+powf((c2->imaginary),2))
 */

