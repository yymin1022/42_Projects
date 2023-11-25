/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:03:06 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/25 11:12:39 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(char x, t_list *stk)
{
	t_list	*tmp;

	if (x != 's')
		if (ft_printf("r%c\n", x) != 3)
			exit_err("Print Error");
	if (stk->size < 2)
		return (0);
	tmp = stk->top->next;
	ft_lstlast(stk->top)->next = stk->top;
	stk->top->next = 0;
	stk->top = tmp;
	return (1);
}

int	rotate_r(t_list *stk_a, t_list *stk_b)
{
	if (ft_printf("rr\n") != 3)
		exit_err("Print Error");
	rotate('s', stk_a);
	rotate('s', stk_b);
	return (1);
}

int	r_rotate(char x, t_list *stk)
{
	t_list	*tmp;

	if (x != 's')
		if (ft_printf("rr%c\n", x) != 4)
			exit_err("Print Error");
	if (stk->size < 2)
		return (0);
	tmp = ft_lstlast(stk->top);
	ft_lstlast_prev(stk->top)->next = 0;
	tmp->next = stk->top;
	stk->top = tmp;
	return (1);
}

int	r_rotate_r(t_list *stk_a, t_list *stk_b)
{
	if (ft_printf("rrr\n") != 4)
		exit_err("Print Error");
	r_rotate('s', stk_a);
	r_rotate('s', stk_b);
	return (1);
}
