/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 19:47:30 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/20 19:48:10 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include "algorithms.h"
# include "utils.h"
# include "operations.h"
# include "parse.h"

int	swap_op(char op[], t_stack **a, t_stack **b);
int	push_op(char op[], t_stack **a, t_stack **b);
int	rotate_op(char op[], t_stack **a, t_stack **b);
int	rrotate_op(char op[], t_stack **a, t_stack **b);

#endif
