#include <stdlib.h>
#include <unistd.h>
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
//	t_stack	*tmp;

	a = NULL;
	b = NULL;
	opts.strategy = ADAPTIVE;
	opts.bench = 0; // will use when --bench is added
	if (!parse_args(ac, av, &opts, &a))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		return (1);
	}
	if (a)
		strategy(&opts, &a, &b);
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
