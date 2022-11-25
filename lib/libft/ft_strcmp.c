/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:47:30 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/25 17:49:58 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int		i;
	const char unsigned	*s1_cast;
	const char unsigned	*s2_cast;

	s1_cast = (const char unsigned *)s1;
	s2_cast = (const char unsigned *)s2;
	i = 0;
	while ((s1_cast[i] != '\0') && (s2_cast[i] != '\0')
		&& (s1_cast[i] == s2_cast[i]))
		i++;
	return (s1_cast[i] - s2_cast[i]);
}
