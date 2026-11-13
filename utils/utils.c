/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 21:53:43 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/13 11:18:21 by moboulah         ###   ########.fr       */
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

int	ft_atoi(const char *c)
{
	int	s;
	int	n;

	n = 0;
	s = 1;
	while (*c == ' ' || (*c >= 9 && *c <= 13))
		c++;
	if (*c == '-' || *c == '+')
	{
		if (*c == '-')
			s = -1;
		c++;
	}
	while (*c >= '0' && *c <= '9')
	{
		n = n * 10 + (*c - '0');
		c++;
	}
	return (n * s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
