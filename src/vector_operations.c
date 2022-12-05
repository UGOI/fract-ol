/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:58:13 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/29 20:23:05 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"
#include <math.h>

t_vector	add_vector(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	return (res);
}

t_vector	sub_vector(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	return (res);
}
