/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:23:17 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/17 00:00:25 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*get_strategy(int strat, double disorder)
{
	char	*str;

	if (strat == SIMPLE)
		str = "Simple / O(n^2)";
	else if (strat == MEDIUM)
		str = "Medium / O(n√n)";
	else if (strat == COMPLEX)
		str = "Complex / O(nlogn)";
	else 
	{
		if (disorder < 0.2)
			str = "Adaptive / O(n^2)";
		else if (disorder < 0.5)
			str = "Adaptive / O(n√n)";
		else
			str = "Adaptive / O(nlogn)";
	}
	return (str);
}

static int	get_total_ops(t_bench *bench)
{
	return (bench->pa + bench->pb + bench->sa 
		+ bench->sb + bench->ss + bench->ra 
		+ bench->rb + bench->rr + bench->rra 
		+ bench->rrb + bench->rrr);
}

void	print_bench(t_bench *bench)
{
	double	a;
	int		k;
	int		j;
	
	a = bench->disorder;
	a *= 10000;
	k = a / 100;
	j = (int)a % 100;
	ft_printf("[bench] ");
	ft_printf("disorder: %d.%d%%\n", k, j);
	ft_printf("[bench] ");
	ft_printf("strategy: %s\n",
			get_strategy(bench->strategy, bench->disorder));
	ft_printf("[bench] ");
	ft_printf("total_ops: %d\n", get_total_ops(bench));
	ft_printf("[bench] ");
	ft_printf("sa:\t%u\tsb:\t%u\tss:\t%u\tpa:\t%u\tpb:\t%u\n",
			bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("[bench] ");
	ft_printf("ra:\t%u\trb:\t%u\trr:\t%u\trra:\t%u\trrb:\t%u\trrr:\t%u\n",
			bench->ra, bench->rb, bench->rr,
			bench->rra, bench->rrb, bench->rrr);
}
