/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 09:14:08 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/14 16:43:23 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "operations.h"
#include "utils.h"

static void pass(t_stack **a, int current)
{
	int	i;

	i = 0;
	while (i < current - 1)
	{
		if ((*a)->content < (*a)->next->content)
			sa(a);
		ra(a);
		i++;
	}
}

void	sort_simple(t_stack **a, t_stack **b)
{
	int	current;

	current = ft_stacksize(*a);
	while (current > 1 && !check_sorted(*a))
	{
		pass(a, current);
		pb(b, a);
		current--;
	}
	while (*b)
		pa(a, b);
}
