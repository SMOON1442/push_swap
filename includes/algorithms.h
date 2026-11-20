/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 09:14:17 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/20 03:28:14 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H
# include "operations.h"
# include "utils.h"
# include "ft_printf.h"

void	sort_simple(t_stack **a, t_stack **b);
void	sort_medium(t_stack **a, t_stack **b);
void	sort_complex(t_stack **a, t_stack **b);
typedef struct s_best
{
	int	cost_a;
	int	cost_b;
	int	total;
}		t_best;

int		min_pos(t_stack *a);
int		target_pos(int val, t_stack *a);
int		get_cost(int pos, int size);
int		combined_moves(int cost_a, int cost_b);
void	sort_three(t_stack **a);
void	execute(int cost_a, int cost_b, t_stack **a, t_stack **b);
void	rmin_top(t_stack **a);
void	sort_complex(t_stack **a, t_stack **b);
int		get_pos(t_stack *b, int valeur);
int		index_arr(int n, int *ar, int s);
int		chunk_limit(int n);

#endif
