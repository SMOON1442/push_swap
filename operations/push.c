/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:17:15 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/16 10:39:53 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	push(t_stack **primary, t_stack **auxiliary)
{
	t_stack	*tmp;

	if (!primary || !auxiliary)
		return ;
	tmp = *auxiliary;
	*auxiliary = (*auxiliary)->next;
	tmp->next = *primary;
	*primary = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
