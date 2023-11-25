/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:26:09 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/26 00:59:18 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_2(t_list *stk)
{
	if (stk->top->num > stk->top->next->num)
		swap('a', stk);
}

void	solve_3(t_list *stk)
{
	int	a;
	int	b;
	int	c;

	a = stk->top->num;
	b = stk->top->next->num;
	c = stk->top->next->next->num;
	if (a > b && b < c && a < c)
		swap('a', stk);
	if (a > b && b > c && a > c)
	{
		swap('a', stk);
		r_rotate('a', stk);
	}
	if (a > b && b < c && a > c)
		rotate('a', stk);
	if (a < b && b > c && a < c)
	{
		swap('a', s);
		rotate('a', s);
	}
	if (a < b && b > c && a > c)
		r_rotate('a', s);
}

static void	solve(t_list *stk_a, t_list *stk_b, int size)
{
	int	i;

	i = 0;
	split_stk(stk_a, stk_b, find_pivot(a->top, size), size);
	while (i < size - 3)
	{
		greedy(stk_a, stk_b);
		i++;
	}
	sort_finish(stk_a);
}

void	exit_err(char *str){
	ft_printf("Error: %s\n", str);
	exit(0);
}

int	main(int argc, char **argv)
{
	int		size;
	t_list	stk_a;
	t_list	stk_b;

	stk_a.size = 0;
	stk_b.size = 0;
	if (argc < 2)
		exit_err("Invalid Argument");
	size = parse_input(argc, argv, &stk_a);
	if (size == 1)
		exit(0);
	return (0);
}
