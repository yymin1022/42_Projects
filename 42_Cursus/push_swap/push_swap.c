/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:26:09 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/26 14:00:09 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve(t_stk *stk_a, t_stk *stk_b, int size)
{
	int	i;

	i = 0;
	split_stk(stk_a, stk_b, find_pivot(stk_a->top, size), size);
	while (i < size - 3)
	{
		algo(stk_a, stk_b);
		i++;
	}
	sort_finish(stk_a);
}

static void	solve2(t_stk *stk)
{
	if (stk->top->num > stk->top->next->num)
		swap('a', stk);
}

void	solve3(t_stk *stk)
{
	int	a;
	int	b;
	int	c;

	a = stk->top->num;
	b = stk->top->next->num;
	c = stk->top->next->next->num;
	if (a > b && b > c)
	{
		swap('a', stk);
		r_rotate('a', stk);
	}
	if (a > c && c > b)
		rotate('a', stk);
	if (b > a && a > c)
		r_rotate('a', stk);
	if (b > c && c > a)
	{
		swap('a', stk);
		rotate('a', stk);
	}
	if (c > a && a > b)
		swap('a', stk);
}

void	exit_err(char *str){
	ft_printf("Error: %s\n", str);
	exit(0);
}

int	main(int argc, char **argv)
{
	int		size;
	t_stk	stk_a;
	t_stk	stk_b;

	stk_a.size = 0;
	stk_b.size = 0;
	if (argc < 2)
		exit_err("Invalid Argument");
	size = parse_input(argc, argv, &stk_a);
	if (size == 1)
		exit(0);
	else if (size == 2)
		solve2(&stk_a);
	else if (size == 3)
		solve3(&stk_a);
	else
		solve(&stk_a, &stk_b, size);
	return (0);
}
