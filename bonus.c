#include "algorithms.h"
#include "operations.h"
#include "parse.h"
#include "utils.h"

int     parse_op2(char op[], t_stack **a, t_stack **b)
{
    
    if (!ft_strncmp(op, "sa", 3))
        swap(a);
    else if (!ft_strncmp(op, "sb", 3))
        swap(b);
    else if (!ft_strncmp(op, "ss", 3))
    {
        swap(a);
        swap(b);
    }
    else if (!ft_strncmp(op, "pa", 3))
        push(a, b);
    else if (!ft_strncmp(op, "pb", 3))
        push(b, a);
    else if (!ft_strncmp(op, "ra", 3))
        rotate(a);
    else if (!ft_strncmp(op, "rb", 3))
        rotate(b);
    else if (!ft_strncmp(op, "rr", 3))
    {
        rotate(a);
        rotate(b);
    }
    else
        return (0);
    return (1);
}

int     parse_rrr(char op[], t_stack **a, t_stack **b)
{
    if (!ft_strncmp(op, "rra", 4))
        rrotate(a);
    else if (!ft_strncmp(op, "rrb", 4))
        rrotate(b);
    else if (!ft_strncmp(op, "rrr", 4))
    {
        rrotate(a);
        rrotate(b);
    }
    else
        return (0);
    return (1);
}

int main(int argc,char **argv)
{
    int         i;
	t_stack	*a;
	t_stack	*b;
    char    c;
    char    op[5];

    if (argc < 2)
    {
        return (1);
    }
	a = NULL;
	b = NULL;
	if (!parse_args(argc, argv, NULL, &a))
	{
		ft_printf("Error\n");
		free_stack(&a);
		return (1);
	}

	if (a)
    {
        i = 0;
        while(read(0, &c, 1) > 0)
        {
            if (c == '\n')
            {
                op[i] = '\0';
                if (i == 2)
                {
                    if (!parse_op2(op, &a, &b))
                	{
                        return (ft_printf("Error\n"), free_stack(&a), free_stack(&b), 1);
	                }
                }
                else
                {
                    if (!parse_rrr(op, &a, &b))
                	{
                        ft_printf("Error\n");
                        free_stack(&a);
                        free_stack(&b);
                        return (1);
	                }
                }
                i = 0;
            }
            else
            {
                if (i < 4)
                {
                    op[i] = c;
                    i++;
                }
                else
                {
                    ft_printf("Error\n");
                    free_stack(&a);
                    free_stack(&b);
                    return (1);
                }
            }
        }
    }
    if (!b && check_sorted(a))
    {
        write(1, "OK\n", 3);
    }
    else
    {
        write(1, "KO\n", 3);
    }
    free_stack(&b);
    free_stack(&a);
	return (0);
}