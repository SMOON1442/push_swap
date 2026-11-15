#ifndef PARSE_H
# define PARSE_H
# include "algorithms.h"
# include "utils.h"
# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3

typedef struct s_opts
{
	int		strategy;
	double	bench;
}			t_opts;

int	parse_args(int ac, char **av, t_opts *opts, t_stack **a);

#endif
