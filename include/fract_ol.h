/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:54:38 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/20 19:47:42 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <math.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_complex
{
	float	real;
	float	imaginary;
}	t_complex;

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_fractal
{
	t_vector	top_left;
	t_vector	top_right;
	t_vector	bottom_left;
}	t_fractal;

t_complex	*ft_add_complex(t_complex *c1, t_complex *c2, t_complex *res);

t_complex	*ft_subtract_complex(t_complex *c1, t_complex *c2, t_complex *res);

t_complex	*ft_multiply_complex(t_complex *c1, t_complex *c2, t_complex *res);

t_complex	*ft_divide_complex(t_complex *c1, t_complex *c2, t_complex *res);

float		ft_squared_absolute_complex(t_complex c);

int			mandelbrot(t_complex c);

#endif
