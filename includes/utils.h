/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 21:56:30 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/13 13:18:00 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "operations.h"

int		ft_stacksize(t_stack *a);
t_stack	*ft_stacknew(int a);
void	ft_stack_addback(t_stack **stack, t_stack *new);
int	ft_atoi(const char *c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
