/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:16:37 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/17 22:17:23 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "operations.h"
#include "parse.h"
#include "utils.h"

static void	strategy(t_opts *opts, t_stack **a, t_stack **b)
{
	if (opts->strategy == SIMPLE)
		sort_simple(a, b);
	else
		sort_complex(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_opts	opts;

	a = NULL;
	b = NULL;
	opts.strategy = ADAPTIVE;
	opts.bench = 0;
	if (!parse_args(ac, av, &opts, &a))
	{
		ft_printf("Error\n");
		free_stack(&a);
		return (1);
	}
	if (opts.bench)
	{
		fill_bench()->strategy = opts.strategy;
		fill_bench()->disorder = compute_disorder(&a);
	}
	if (a)
		strategy(&opts, &a, &b);
	if (opts.bench)
		print_bench(fill_bench());
	free_stack(&a);
	return (0);
}
