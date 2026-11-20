/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:19:43 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/17 22:20:47 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		i;
	int		k;
	t_stack	*node;
	char	**arr;

	arr = ft_split(s, ' ');
	k = arr_len(s, ' ');
	i = 0;
	while (arr[i])
	{
		val = ft_atoi(arr[i]);
		if ((!val && *arr[i] != '0') || has_dup(*a, val))
			return (arr_free(arr, k), 0);
		node = ft_stacknew(val);
		if (!node)
			return (arr_free(arr, k), 0);
		ft_stack_addback(a, node);
		i++;
	}
	return (arr_free(arr, k), 1);
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
