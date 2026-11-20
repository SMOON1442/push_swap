/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleghris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 21:20:48 by fleghris          #+#    #+#             */
/*   Updated: 2026/11/20 19:46:26 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

int	index_arr(int n, int *ar, int s)
{
	int	i;

	i = 0;
	while (i < s)
	{
		if (ar[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

int	get_pos(t_stack *b, int valeur)
{
	int	i;

	i = 0;
	while (b)
	{
		if (b->content == valeur)
			return (i);
		b = b->next;
		i++;
	}
	return (-1);
}

int	chunk_limit(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i * i >= n)
			return (i);
		i++;
	}
	return (-1);
}
