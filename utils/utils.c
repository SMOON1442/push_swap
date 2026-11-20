/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 21:53:43 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/16 14:36:27 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	ft_stacksize(t_stack *a)
{
	int	count;

	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

t_stack	*ft_stacknew(int a)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->content = a;
	stack->next = NULL;
	return (stack);
}

void	ft_stack_addback(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	check_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_stack(t_stack **s)
{
	t_stack	*tmp;

	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
}
