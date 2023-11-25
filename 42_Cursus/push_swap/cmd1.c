/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:55:48 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/25 11:12:22 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(char x, t_list *stk_from, t_list *stk_to)
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

int	swap(char x, t_list *stk)
{
	t_list	*tmp;

	if (x != 's')
		if (ft_printf("s%c\n", x) != 3)
			exit_err("Print Error");
	if (stk->size < 2)
		return (0);
	tmp = s->top->next;
	s->top->next = tmp->next;
	tmp->next = s->top;
	s->top = tmp;
	return (1);
}

int	swap_s(t_list *stk_a, t_list *stk_b)
{
	if (ft_printf("ss\n") != 3)
		exit_err("Print Error");
	swap('x', stk_a);
	swap('x', stk_b);
	return (1);
}
