#include "algorithms.h"
#include "operations.h"
#include "utils.h"

static void	rotate_a(t_stack **a, int c)
{
	while (c > 0)
	{
		ra(a);
		c--;
	}
	while (c < 0)
	{
		rra(a);
		c++;
	}
}

static void	rotate_b(t_stack **b, int c)
{
	while (c > 0)
	{
		rb(b);
		c--;
	}
	while (c < 0)
	{
		rrb(b);
		c++;
	}
}

void	execute(int cost_a, int cost_b, t_stack **a, t_stack **b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	rotate_a(a, cost_a);
	rotate_b(b, cost_b);
}

void	rmin_top(t_stack **a)
{
	rotate_a(a, get_cost(min_pos(*a), ft_stacksize(*a)));
}

void	sort_three(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->content;
	y = (*a)->next->content;
	z = (*a)->next->next->content;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}
