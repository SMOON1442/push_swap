/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:20:49 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/14 16:43:39 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "operations.h"
#include "utils.h"

static int	get_bit(int value, int bit)
{
	unsigned int	u;

	u = (unsigned int)value + SIGN_BIT;
	return ((u >> bit) & 1);
}

static void	pass(t_stack **a, t_stack **b, int size, int bit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (get_bit((*a)->content, bit))
			ra(a);
		else
			pb(b, a);
		i++;
	}
	while (*b)
		pa(a, b);
}

void	sort_complex(t_stack **a, t_stack **b)
{
	int	size;
	int	bit;

	size = ft_stacksize(*a);
	bit = 0;
	while (bit < 32 && !check_sorted(*a))
	{
		pass(a, b, size, bit);
		bit++;
	}
}
