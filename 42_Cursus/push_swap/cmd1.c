/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:55:48 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/26 11:57:37 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(char x, t_stk *stk_to, t_stk *stk_from)
{
	t_list	*tmp;

	if (ft_printf("p%c\n", x) != 3)
		exit_err("Print Error");
	if (stk_from->size == 0)
		return (0);
	tmp = stk_from->top;
	stk_from->top = stk_from->top->next;
	ft_lstadd_front(&(stk_to->top), tmp);
	(stk_from->size)--;
	(stk_to->size)++;
	return (1);
}

int	swap(char x, t_stk *stk)
{
	t_list	*tmp;

	if (x != 's')
		if (ft_printf("s%c\n", x) != 3)
			exit_err("Print Error");
	if (stk->size < 2)
		return (0);
	tmp = stk->top->next;
	stk->top->next = tmp->next;
	tmp->next = stk->top;
	stk->top = tmp;
	return (1);
}

int	swap_s(t_stk *stk_a, t_stk *stk_b)
{
	if (ft_printf("ss\n") != 3)
		exit_err("Print Error");
	swap('s', stk_a);
	swap('s', stk_b);
	return (1);
}
