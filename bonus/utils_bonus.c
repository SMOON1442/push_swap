#include "bonus.h"

int	swap_op(char op[], t_stack **a, t_stack **b)
{
	if (!ft_strncmp(op, "sa", 3))
		swap(a);
	else if (!ft_strncmp(op, "sb", 3))
		swap(b);
	else if (!ft_strncmp(op, "ss", 3))
	{
		swap(a);
		swap(b);
	}
	else
		return (0);
	return (1);
}

int	push_op(char op[], t_stack **a, t_stack **b)
{
	if (!ft_strncmp(op, "pa", 3))
		push(a, b);
	else if (!ft_strncmp(op, "pb", 3))
		push(b, a);
	else
		return (0);
	return (1);
}

int	rotate_op(char op[], t_stack **a, t_stack **b)
{
	if (!ft_strncmp(op, "ra", 3))
		rotate(a);
	else if (!ft_strncmp(op, "rb", 3))
		rotate(b);
	else if (!ft_strncmp(op, "rr", 3))
	{
		rotate(a);
		rotate(b);
	}
	else
		return (0);
	return (1);
}

int	rrotate_op(char op[], t_stack **a, t_stack **b)
{
	if (!ft_strncmp(op, "rra", 4))
		rrotate(a);
	else if (!ft_strncmp(op, "rrb", 4))
		rrotate(b);
	else if (!ft_strncmp(op, "rrr", 4))
	{
		rrotate(a);
		rrotate(b);
	}
	else
		return (0);
	return (1);
}
