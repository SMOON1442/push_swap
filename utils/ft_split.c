/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 10:59:05 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/15 11:30:48 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t	arr_len(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

int	arr_free(char **arr, size_t k)
{
	size_t	i;

	i = 0;
	while (i < k)
		free(arr[i++]);
	free(arr);
	return (0);
}

static int	arr_fill(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			while (s[i + j] && s[i + j] != c)
				j++;
			arr[k] = malloc(j + 1);
			if (!arr[k])
				return (arr_free(arr, k));
			ft_strlcpy(arr[k++], s + i, j + 1);
			i += j;
		}
		else
			i++;
	}
	arr[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((arr_len(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!arr_fill(arr, s, c))
		return (NULL);
	return (arr);
}
