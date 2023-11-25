/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 01:04:51 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/26 02:23:17 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cnt_stk_a(t_stk *stk_a, long long val)
{
	int			i;
	int			min_i;
	long long	min_delta;
	t_list		*tmp;

	i = 0;
	min_delta = 2147483648 * 2;
	tmp = stk_a->top;
	while (i < stk_a->size)
	{
		if (val < tmp->num)
		{
			if (tmp->num - val < min_delta)
			{
				min_delta = tmp->num - val;
				min_i = i;
			}
		}
		tmp = tmp->next;
		i++;
	}
	return (min_i);
}

static void	run_cmd(t_stk *stk_a, t_stk *stk_b, t_cnt cnt)
{
	while (cnt.total > 0)
	{
		if (cnt.ra > 0)
			cnt.ra -= rotate('a', stk_a);
		else if (cnt.rb > 0)
			cnt.rb -= rotate('b', stk_b);
		else if (cnt.rr > 0)
			cnt.rr -= rotate_r(stk_a, stk_b);
		else if (cnt.rra > 0)
			cnt.rra -= r_rotate('a', stk_a);
		else if (cnt.rrb > 0)
			cnt.rrb -= r_rotate('b', stk_b);
		else if (cnt.rrr > 0)
			cnt.rrr -= r_rotate_r(stk_a, stk_b);
		cnt.total--;
	}
	push('a', stk_a, stk_b);
}

void	algo(t_stk *stk_a, t_stk *stk_b)
{
	int		i;
	t_cnt	cnt;
	t_cnt	min_cnt;
	t_list	*tmp;

	i = 0;
	min_cnt.total = 2147483647;
	tmp = stk_b->top;
	while (i < stk_b->size)
	{
		cnt = calc_cnt(stk_a, stk_b, i, tmp->num);
		if (cnt.total < min_cnt.total)
			min_cnt = cnt;
		i++;
		tmp = tmp->next;
	}
	run_cmd(stk_a, stk_b, min_cnt);
}
