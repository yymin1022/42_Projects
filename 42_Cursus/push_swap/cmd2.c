/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:03:06 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/26 15:24:26 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(char x, t_stk *stk)
{
	t_list	*tmp;

	if (x != 's')
		if (ft_printf("r%c\n", x) != 3)
			exit_err();
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
	if (ft_printf("rr\n") != 3)
		exit_err();
	rotate('s', stk_a);
	rotate('s', stk_b);
	return (1);
}

int	r_rotate(char x, t_stk *stk)
{
	t_list	*tmp;

	if (x != 's')
		if (ft_printf("rr%c\n", x) != 4)
			exit_err();
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
	if (ft_printf("rrr\n") != 4)
		exit_err();
	r_rotate('s', stk_a);
	r_rotate('s', stk_b);
	return (1);
}
