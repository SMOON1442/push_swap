/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:09:39 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/16 18:42:15 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_stack **a)
{
	swap(a);
	fill_bench()->sa++;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	fill_bench()->sb++;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	fill_bench()->ss++;
	write(1, "ss\n", 3);
}
