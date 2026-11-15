#include "algorithms.h"
#include "operations.h"
#include "utils.h"
#include <limits.h>

static t_best	best_move(t_stack *a, t_stack *b)
{
	int		i;
	int		na;
	int		nb;
	t_best	cur;
	t_best	best;

	i = 0;
	na = ft_stacksize(a);
	nb = ft_stacksize(b);
	best.total = INT_MAX;
	while (b)
	{
		cur.cost_a = get_cost(target_pos(b->content, a), na);
		cur.cost_b = get_cost(i, nb);
		cur.total = combined_moves(cur.cost_a, cur.cost_b);
		if (cur.total < best.total)
			best = cur;
		b = b->next;
		i++;
	}
	return (best);
}

void	sort_complex(t_stack **a, t_stack **b)
{
	int		n;
	t_best	best;

	if (check_sorted(*a))
		return ;
	n = ft_stacksize(*a);
	if (n == 2)
		sa(a);
	else if (n == 3)
		sort_three(a);
	else
	{
		while (n-- > 3)
			pb(b, a);
		sort_three(a);
		while (*b)
		{
			best = best_move(*a, *b);
			execute(best.cost_a, best.cost_b, a, b);
			pa(a, b);
		}
		rmin_top(a);
	}
}
