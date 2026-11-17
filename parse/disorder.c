/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 10:59:12 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/16 14:35:44 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static unsigned int	mistake(t_stack *node, int i, int k)
{
	t_stack			*tmp;
	int				j;
	unsigned int	mistakes;

	tmp = node->next;
	j = i + 1;
	mistakes = 0;
	while (j < k - 1)
	{
		if (node->content > tmp->content)
			mistakes++;
		j++;
		tmp = tmp->next;
	}
	return (mistakes);
}

static unsigned int	pairs(t_stack *node, int i, int k)
{
	t_stack			*tmp;
	int				j;
	unsigned int	pairs;

	tmp = node->next;
	j = i + 1;
	pairs = 0;
	while (j < k - 1)
	{
		pairs++;
		j++;
		tmp = tmp->next;
	}
	return (pairs);
}

double	compute_disorder(t_stack **a)
{
	unsigned int	mistakes;
	unsigned int	total_pairs;
	int				i;
	int				k;
	t_stack			*tmp;

	mistakes = 0;
	total_pairs = 0;
	k = ft_stacksize(*a);
	i = 0;
	tmp = *a;
	while (i < k - 1)
	{
		total_pairs += pairs(tmp, i, k);
		mistakes += mistake(tmp, i, k);
		i++;
		tmp = tmp->next;
	}
	if (!total_pairs)
		return (0);
	return ((double)mistakes / total_pairs);
}
