/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:57:58 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/16 21:36:55 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	if (!((*stack)->next->next))
	{
		(*stack)->next->next = *stack;
		*stack = (*stack)->next;
		(*stack)->next->next = NULL;
		return ;
	}
	tmp = (*stack)->next;
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = *stack;
	(*stack)->next = NULL;
	*stack= tmp;
}

void	ra(t_stack **a)
{
	rotate(a);
	fill_bench()->ra++;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	fill_bench()->rb++;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	fill_bench()->rr++;
	write(1, "rr\n", 3);
}
