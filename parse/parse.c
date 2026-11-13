#include <limits.h>
#include "parse.h"

static int	parse_flag(char *s, t_opts *opts)
{
	if (!ft_strncmp(s, "--simple", 9))
		opts->strategy = SIMPLE;
	else if (!ft_strncmp(s, "--medium", 9))
		opts->strategy = MEDIUM;
	else if (!ft_strncmp(s, "--complex", 10))
		opts->strategy = COMPLEX;
	else if (!ft_strncmp(s, "--adaptive", 11))
		opts->strategy = ADAPTIVE;
	else if (!ft_strncmp(s, "--bench", 8))
		opts->bench = 1;
	else
		return (0);
	return (1);
}

static int	has_dup(t_stack *a, int val)
{
	while (a)
	{
		if (a->content == val)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	add_number(t_stack **a, char *s)
{
	int		val;
	t_stack	*node;

	val = ft_atoi(s);
	if (!val || has_dup(*a, val))
		return (0);
	node = ft_stacknew(val);
	if (!node)
		return (0);
	ft_stack_addback(a, node);
	return (1);
}

int	parse_args(int ac, char **av, t_opts *opts, t_stack **a)
{
	int	i;
	int	checker;

	i = 1;
	while (i < ac)
	{
		if (!ft_strncmp(av[i], "--", 2))
			checker = parse_flag(av[i], opts);
		else
			checker = add_number(a, av[i]);
		if (!checker)
			return (0);
		i++;
	}
	return (1);
}
