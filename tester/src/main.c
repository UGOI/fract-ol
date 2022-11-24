/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:49:45 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/24 03:09:45 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
//#include "../../lib/MLX42/MLX42.h"
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

// int	ft_random(int min, int max)
// {
// 	return (min + rand() / (RAND_MAX / (max - min + 1) + 1));
// }

// void	fill_complex_number_with_random_values(t_complex *c)
// {
// 	c->real = ft_random(-10, 10);
// 	c->imaginary = ft_random(-10, 10);
// }

// void	test_complex(t_complex *(*f)(t_complex*, t_complex*, t_complex*), char operator)
// {
// 	t_complex		c1;
// 	t_complex		c2;
// 	t_complex		res;
// 	double complex	expected_res;
// 	int				iter;

// 	iter = 6;
// 	while (iter--)
// 	{
// 		fill_complex_number_with_random_values(&c1);
// 		fill_complex_number_with_random_values(&c2);

// 		// c1.real = -0.77;
// 		// c1.imaginary = 0.18;
// 		// c2.real = -0.77;
// 		// c2.imaginary = 0.18;
// 		// printf("c1:	%.2f %+.2f\nc2:	%.2f %+.2f\n", c1.real, c1.imaginary, c2.real, c2.imaginary);
// 		if (operator == '+')
// 			expected_res = (c1.real + c1.imaginary * I) + (c2.real + c2.imaginary * I);
// 		if (operator == '-')
// 			expected_res = (c1.real + c1.imaginary * I) - (c2.real + c2.imaginary * I);
// 		if (operator == '*')
// 			expected_res = (c1.real + c1.imaginary * I) * (c2.real + c2.imaginary * I);
// 		if (operator == '/')
// 			expected_res = (c1.real + c1.imaginary * I) / (c2.real + c2.imaginary * I);
// 		printf("Expected result:	%.3f %+.3fi\n", creal(expected_res), cimag(expected_res));
// 		(*f)(&c1, &c2, &res);
// 		printf("Result:			%.3Lf %+.3Lfi\n\n", res.real, res.imaginary);
// 	}
// }

// void	test_add_complex(void)
// {
// 	printf("%s\n\n	TEST_ADD_COMPLEX:	\n", KYEL);
// 	printf("%s",KNRM);
// 	test_complex(ft_add_complex, '+');
// }

// void	test_subtract_complex(void)
// {
// 	printf("%s	TEST_SUBTRACT_COMPLEX:	\n", KYEL);
// 	printf("%s",KNRM);
// 	test_complex(ft_subtract_complex, '-');
// }

// void	test_multiply_complex(void)
// {
// 	printf("%s	TEST_MULTIPLY_COMPLEX:	\n", KYEL);
// 	printf("%s",KNRM);
// 	test_complex(ft_multiply_complex, '*');
// }

// void	test_divide_complex(void)
// {
// 	printf("%s	TEST_DIVIDE_COMPLEX:	\n", KYEL);
// 	printf("%s",KNRM);
// 	test_complex(ft_divide_complex, '/');
// }

// void	test_squared_abolute_complex(void)
// {
// 	t_complex		c;
// 	float			squared_absolute_complex;
// 	float			result;
// 	int				iterations;

// 	iterations = 6;
// 	printf("%s	TEST_SQUARED_ABSOLUTE_COMPLEX:	\n", KYEL);
// 	printf("%s",KNRM);

// 	while (iterations--)
// 	{
// 		fill_complex_number_with_random_values(&c);
// 		result = powf(cabsf(c.real + c.imaginary * I),2);
// 		squared_absolute_complex = ft_squared_absolute_complex(c);
// 		// printf("c:	%.2f %+.2f\n", c.real, c.imaginary);
// 		printf("Expected result:	%.3f\n", result);
// 		printf("Result:			%.3f\n\n", squared_absolute_complex);
// 	}

// }

void	test_pow_complex(void)
{
	t_complex c1 = {2, 0};
	long double pow = 2;
	t_complex res;

	res = ft_power_complex(c1, pow);

	printf("%Lf %+Lfi\n", res.real, res.imaginary);
}

// void	test_mandelbrot(void)
// {
// 	t_complex		c;
// 	int				iterations;

// 	c.real = 0.0000000000;
// 	c.imaginary = -1.0000000000;
// 	printf("%s	TEST_MANDELBROT:	\n", KYEL);
// 	printf("%s",KNRM);
// 	iterations = mandelbrot(c);
// 	printf("Result: %d\n\n", iterations);
// }

int	main(void)
{
	// test_add_complex();
	// test_subtract_complex();
	// test_multiply_complex();
	// test_divide_complex();
	// test_mandelbrot();
	// test_squared_abolute_complex();
	test_pow_complex();

	return (0);
}
