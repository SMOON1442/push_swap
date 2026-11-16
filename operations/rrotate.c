/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 23:45:04 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/16 10:44:46 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rrotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*previous;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	if (!((*stack)->next->next))
	{
		(*stack)->next->next = *stack;
		*stack = (*stack)->next;
		(*stack)->next->next = NULL;
		return ;
	}
	previous = *stack;
	current = previous->next;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	current->next = *stack;
	*stack = current;
}

void	rra(t_stack **a)
{
	rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}
