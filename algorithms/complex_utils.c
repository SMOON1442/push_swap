/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:38:23 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/16 14:53:00 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

int	min_pos(t_stack *a)
{
	int	i;
	int	pos;
	int	min;

	i = 0;
	pos = 0;
	min = a->content;
	while (a)
	{
		if (a->content < min)
		{
			min = a->content;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}

static int	bigger_pos(int val, t_stack *a)
{
	int	i;
	int	pos;
	int	best;

	i = 0;
	pos = -1;
	best = 0;
	while (a)
	{
		if (a->content > val && (pos < 0 || a->content < best))
		{
			best = a->content;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}

int	target_pos(int val, t_stack *a)
{
	int	pos;

	pos = bigger_pos(val, a);
	if (pos < 0)
		return (min_pos(a));
	return (pos);
}

int	get_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

int	combined_moves(int cost_a, int cost_b)
{
	if (cost_a * cost_b > 0)
	{
		if (ft_abs(cost_a) >= ft_abs(cost_b))
			return (ft_abs(cost_a));
		return (ft_abs(cost_b));
	}
	return (ft_abs(cost_a) + ft_abs(cost_b));
}
