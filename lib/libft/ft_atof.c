/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:13:08 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/05 16:19:14 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<limits.h>
#include<stdio.h>
#include <string.h>
#include"libft.h"
#include"math.h"

float	ft_atof(const char *str)
{
	char	*after_point;
	char	*at_point;
	size_t	len_after_point;
	char	str_copy[100];

	ft_strlcpy(str_copy, str, 100);
	if (ft_strchr(str_copy, '.') == NULL)
		return (ft_atoi(str_copy));
	at_point = ft_strchr(str_copy, '.');
	after_point = at_point + 1;
	len_after_point = ft_strlen(after_point) + 1;
	ft_memmove(at_point, after_point, len_after_point);
	return (ft_atoi(str_copy) / pow(10, len_after_point - 1));
}
