/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 10:59:12 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/16 11:18:08 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	compute_disorder(t_stack **a)
{
	unsigned int	mistakes;
	unsigned int	total_pairs;
	int				i;
	int				j;
	int				k;
	t_stack			*tmp1;
	t_stack			*tmp2;

	mistakes = 0;
	total_pairs = 0;
	k = ft_stacksize(*a);
	i = 0;
	tmp1 = *a;
	while (i < k - 1)
	{
		tmp2 = tmp1->next;
		j = i + 1;
		while (j < k - 1)
		{
			total_pairs++;
			if (tmp1->content > tmp2->content)
				mistakes++;
			j++;
			tmp2 = tmp2->next;
		}
		i++;
		tmp1 = tmp1->next;
	}
	if (!total_pairs)
		return (0);
	return ((double)mistakes / total_pairs);
}
