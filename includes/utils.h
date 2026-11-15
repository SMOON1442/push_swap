/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 21:56:30 by moboulah          #+#    #+#             */
/*   Updated: 2026/11/15 11:36:26 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "operations.h"

int		ft_stacksize(t_stack *a);
t_stack	*ft_stacknew(int a);
void	ft_stack_addback(t_stack **stack, t_stack *new);
void	free_stack(t_stack **s);
int	check_sorted(t_stack *a);
int	ft_atoi(const char *c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
int	arr_free(char **arr, size_t k);
size_t	arr_len(char const *s, char c);

#endif
