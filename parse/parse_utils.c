/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 11:03:21 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/16 16:04:46 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <limits.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_atoi(const char *c)
{
	int		s;
	long	n;

	n = 0;
	s = 1;
	while (*c == ' ' || (*c >= 9 && *c <= 13))
		c++;
	if (*c == '-' || *c == '+')
	{
		if (*c == '-')
			s = -1;
		c++;
	}
	while (*c >= '0' && *c <= '9')
	{
		n = n * 10 + (*c - '0');
		if (n > 2147483647)
			return (0);
		c++;
	}
	if (*c)
		return (0);
	return (n * s);
}
