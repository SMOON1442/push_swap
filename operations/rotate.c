/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:57:58 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/14 23:44:24 by moboulah         ###   ########.fr       */
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
