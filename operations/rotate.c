/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:57:58 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/13 12:11:10 by moboulah         ###   ########.fr       */
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
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

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
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	rrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");
}
