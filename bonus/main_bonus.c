/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 19:49:14 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/20 19:49:16 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	fail(t_stack **a, t_stack **b)
{
	write(2, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	return (1);
}

int	execute_op(t_stack **a, t_stack **b, char op[], int i)
{
	op[i] = '\0';
	if (i == 2)
	{
		if (op[0] == 's')
			return (swap_op(op, a, b));
		if (op[0] == 'p')
			return (push_op(op, a, b));
		if (op[0] == 'r')
			return (rotate_op(op, a, b));
	}
	else if (i == 3 && op[0] == 'r')
		return (rrotate_op(op, a, b));
	return (0);
}

static int	read_ops(t_stack **a, t_stack **b)
{
	char	c;
	char	op[5];
	int		i;

	i = 0;
	while (read(0, &c, 1) > 0)
	{
		if (c != '\n')
		{
			if (i >= 4)
				return (0);
			op[i++] = c;
		}
		else
		{
			if (!execute_op(a, b, op, i))
				return (0);
			i = 0;
		}
	}
	return (i == 0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!parse_args(argc, argv, NULL, &a) || !read_ops(&a, &b))
		return (fail(&a, &b));
	if (!b && check_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&b);
	free_stack(&a);
	return (0);
}
