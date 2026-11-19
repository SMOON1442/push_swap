#include "algorithms.h"

void    sort_arr(int *arr, int n)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < n - 1)
    {
        j = 0;
        while (j < n - 1 - i)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

void a_to_b(t_stack **a, t_stack **b, int *arr, int limit)
{
    int i;
    int sz;
    int end;
    int pushed;

    sz = ft_stacksize(*a);
    end = limit;
    pushed = 0;
    while (*a)
    {
        i = index_arr((*a)->content, arr, sz);
        if (i < end)
        {
            pb(b, a);
            pushed++;
            if (pushed == end)
                end += limit;
        }
        else
            ra(a);
    }
}

void b_to_a(t_stack **a, t_stack **b, int *arr, int sz)
{
    int i;

    i = 0;
    while (*b)
    {
        i = get_pos(*b, arr[sz - 1]);
        if (i <= sz / 2)
            while (i > 0)
            {
                if (i == 1)
                    sb(b);
                else
                    rb(b);
                i--;
            }
        else
            while (i++ < sz)
                rrb(b);
        pa(a, b);
        sz--;
    }
}

int     chunk_limit(int n)
{
    int i;

    i = 0;
    while(i < n)
    {
        if (i * i >= n)
            return (i);
        i++;
    }
    return (-1);
}

int     index_arr(int n, int *ar, int s)
{
    int i;

    i = 0;
    while (i < s)
    {
        if (ar[i] == n)
            return (i);
        i++;
    }
    return (-1);
}

int     get_pos(t_stack *b, int valeur)
{
    int i;

    i = 0;
    while (b)
    {
        if (b->content == valeur)
            return (i);
        b = b->next;
        i++;
    }
    return (-1);
}

void    fill_arr(t_stack *a, int *arr, int sz)
{
    int i;

    i = 0;
    while (i < sz)
    {
        arr[i] = a->content;
        i++;
        a = a->next;
    }
    sort_arr(arr, sz);
}

void	sort_medium(t_stack **a, t_stack **b)
{
    int sz;
    int limit;
    int *arr;
    
    sz = ft_stacksize(*a);
    arr = malloc(sz * sizeof(int));
    if (!arr)
        return ;
    fill_arr(*a, arr, sz);
    limit = chunk_limit(sz);
    a_to_b(a, b, arr, limit);
    b_to_a(a, b, arr, sz);
    free(arr);
}