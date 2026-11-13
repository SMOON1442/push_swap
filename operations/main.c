#include <stdlib.h>
#include <unistd.h>
#include "algorithms.h"
#include "operations.h"
#include "parse.h"
#include "utils.h"

static void	free_stack(t_stack **s)
{
	t_stack	*tmp;

	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
}

static void	run_strategy(t_opts *opts, t_stack **a, t_stack **b)
{
	(void)opts; // will use after adding other algos
	sort_simple(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_opts	opts;
//	t_stack	*tmp;

	a = NULL;
	b = NULL;
	opts.strategy = ADAPTIVE;
	opts.bench = 0;
	if (!parse_args(ac, av, &opts, &a))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		return (1);
	}
	if (a)
		run_strategy(&opts, &a, &b);
/*
	tmp = a;
	while (tmp)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
*/
	free_stack(&a);
	return (0);
}
