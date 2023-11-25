/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 01:44:25 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/26 02:24:14 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case0(t_cnt *cnt)
{
	cnt->rr = min(cnt->ra, cnt->rb);
	cnt->ra -= cnt->rr;
	cnt->rb -= cnt->rr;
	cnt->rra = 0;
	cnt->rrb = 0;
	cnt->rrr = 0;
	cnt->total = cnt->ra + cnt->rb + cnt->rr;
}

static void	case1(t_cnt *cnt)
{
	cnt->ra = 0;
	cnt->rr = 0;
	cnt->rrb = 0;
	cnt->rrr = 0;
	cnt->total = cnt->rb + cnt->rra;
}

static void	case2(t_cnt *cnt)
{
	cnt->rb = 0;
	cnt->rr = 0;
	cnt->rra = 0;
	cnt->rrr = 0;
	cnt->total = cnt->ra + cnt->rrb;
}

static void	case3(t_cnt *cnt)
{
	cnt->ra = 0;
	cnt->rb = 0;
	cnt->rr = 0;
	cnt->rrr = min(cnt->rra, cnt->rrb);
	cnt->rra -= cnt->rrr;
	cnt->rrb -= cnt->rrr;
	cnt->total = cnt->rra + cnt->rrb + cnt->rrr;
}

t_cnt	calc_cnt(t_stk *stk_a, t_stk *stk_b, int idx, int tmp)
{
	int		arr[4];
	int		best;
	t_cnt	cnt;

	cnt.rb = idx;
	cnt.rrb = stk_b->size - idx;
	cnt.ra = calc_cnt_stk_a(stk_a, tmp);
	cnt.rra = stk_a->size - cnt.ra;
	arr[0] = max(cnt.ra, cnt.rb);
	arr[1] = cnt.rb + cnt.rra;
	arr[2] = cnt.rrb + cnt.ra;
	arr[3] = max(cnt.rra, cnt.rrb);
	best = get_min_idx(arr, 4);
	if (best == 0)
		case0(&cnt);
	else if (best == 1)
		case1(&cnt);
	else if (best == 2)
		case2(&cnt);
	else if (best == 3)
		case3(&cnt);
	return (cnt);
}
