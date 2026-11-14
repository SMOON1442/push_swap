/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 09:14:17 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/14 14:24:32 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H
# include "operations.h"
# include "utils.h"
# include "ft_printf.h"
# define SIGN_BIT 0x80000000u;

void	sort_simple(t_stack **a, t_stack **b);
void	sort_medium(t_stack **a, t_stack **b);
void	sort_complex(t_stack **a, t_stack **b);

#endif
