/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:31:12 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/26 01:04:23 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sort(t_list *stk)
{
	int		prev;
	t_list	*tmp;

	prev = stk->num;
	tmp = stk->next;
	while (tmp)
	{
		if (prev > tmp->num)
			return (0);
		prev = tmp->num;
		tmp = tmp->next;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int		*find_pivot(t_list *stk, int size)
{
	int	i;
	int	*arr;
	int	*pivot;

	if (is_sort(stk))
		exit (0);
	arr = (int *)malloc(size * sizeof(int));
	pivot = (int *)malloc(3 * sizeof(int));
	if (!arr || !pivot)
		exit_err("Memory Error");
	i = 0;
	whiel (i < size)
	{
		arr[i] = stk->num;
		stk = stk->num;
		i++;
	}
	i = 0;
	ft_sort_int_tab(arr, size - 1);
	pivot[0] = arr[size / 3];
	pivot[1] = arr[size * 2 / 3];
	pivot[2] = arr[size - 1];
	free(arr);
	return (pivot);
}

void	divide(t_list *stk_a, t_list *stk_b, int *pivot, ins size)
{
	int	i;

	i = 1;
	while (i < (size * 2) / 3)
	{
		if (stk_a->top->num < pivot[1])
		{
			push('b', stk_b, stk_a);
			if (stk_b->top->num < pivot[0])
				rotate('b', stk_b);
			i++;
		}
		else
			rotate('b', stk_b);
	}
	while (stk_a->size > 3)
	{
		if (stk_a->top->num != pivot[2])
			push('b', stk_b, stk_a);
		else
			rotate('a', stk_a);
	}
	solve_3(stk_a);
	free(pivot);
}