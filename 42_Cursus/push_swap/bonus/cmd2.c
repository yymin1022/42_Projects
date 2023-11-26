/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:03:06 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/27 02:46:50 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rotate(t_stk *stk)
{
	t_list	*tmp;

	if (stk->size < 2)
		return (0);
	tmp = stk->top->next;
	ft_lstlast(stk->top)->next = stk->top;
	stk->top->next = 0;
	stk->top = tmp;
	return (1);
}

int	rotate_r(t_stk *stk_a, t_stk *stk_b)
{
	rotate(stk_a);
	rotate(stk_b);
	return (1);
}

int	r_rotate(t_stk *stk)
{
	t_list	*tmp;

	if (stk->size < 2)
		return (0);
	tmp = ft_lstlast(stk->top);
	ft_lstlast_prev(stk->top)->next = 0;
	tmp->next = stk->top;
	stk->top = tmp;
	return (1);
}

int	r_rotate_r(t_stk *stk_a, t_stk *stk_b)
{
	r_rotate(stk_a);
	r_rotate(stk_b);
	return (1);
}
