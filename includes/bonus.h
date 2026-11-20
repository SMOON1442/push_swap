#ifndef BONUS_H
# define BONUS_H
# include "algorithms.h"
# include "utils.h"
# include "operations.h"
# include "parse.h"

int     swap_op(char op[], t_stack **a, t_stack **b);
int     push_op(char op[], t_stack **a, t_stack **b);
int     rotate_op(char op[], t_stack **a, t_stack **b);
int     rrotate_op(char op[], t_stack **a, t_stack **b);

#endif