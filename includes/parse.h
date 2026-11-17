/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:16:04 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/17 22:16:22 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_atoi(const char *c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		parse_args(int ac, char **av, t_opts *opts, t_stack **a);
char	**ft_split(char const *s, char c);
double	compute_disorder(t_stack **a);

#endif
