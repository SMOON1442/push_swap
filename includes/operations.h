/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 09:34:38 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/16 22:39:00 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

typedef struct s_bench
{
	double			disorder;
	unsigned int	sa;
	unsigned int	sb;
	unsigned int	ss;
	unsigned int	pa;
	unsigned int	pb;
	unsigned int	ra;
	unsigned int	rb;
	unsigned int	rr;
	unsigned int	rra;
	unsigned int	rrb;
	unsigned int	rrr;
	int				strategy;
}					t_bench;

t_bench	*fill_bench(void);

typedef struct s_stack
{
	int					content;
	struct s_stack		*next;
}						t_stack;

void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **primary, t_stack **auxiliary);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
