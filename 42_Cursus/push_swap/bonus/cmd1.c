/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:55:48 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/27 03:13:27 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_cmd_valid(t_stk *stk_a, t_stk *stk_b, char *cmd)
{
	if (ft_strlen(cmd) == 3 && cmd[0] == 's' && cmd[1] == 'a')
		return (swap(stk_a));
	if (ft_strlen(cmd) == 3 && cmd[0] == 's' && cmd[1] == 'b')
		return (swap(stk_b));
	if (ft_strlen(cmd) == 3 && cmd[0] == 's' && cmd[1] == 'b')
		return (swap_s(stk_a, stk_b));
	if (ft_strlen(cmd) == 3 && cmd[0] == 'p' && cmd[1] == 'a')
		return (push(stk_a, stk_b));
	if (ft_strlen(cmd) == 3 && cmd[0] == 'p' && cmd[1] == 'b')
		return (push(stk_b, stk_a));
	if (ft_strlen(cmd) == 3 && cmd[0] == 'r' && cmd[1] == 'a')
		return (rotate(stk_a));
	if (ft_strlen(cmd) == 3 && cmd[0] == 'r' && cmd[1] == 'b')
		return (rotate(stk_b));
	if (ft_strlen(cmd) == 3 && cmd[0] == 'r' && cmd[1] == 'r')
		return (rotate_r(stk_a, stk_b));
	if (ft_strlen(cmd) == 4 && cmd[0] == 'r' && cmd[1] == 'r' \
			&& cmd[2] == 'a')
		return (r_rotate(stk_a));
	if (ft_strlen(cmd) == 4 && cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'b')
		return (r_rotate(stk_b));
	if (ft_strlen(cmd) == 4 && cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'r')
		return (r_rotate_r(stk_a, stk_b));
	return (-1);
}

int	push(t_stk *stk_to, t_stk *stk_from)
{
	t_list	*tmp;

	if (stk_from->size == 0)
		return (0);
	tmp = stk_from->top;
	stk_from->top = stk_from->top->next;
	ft_lstadd_front(&(stk_to->top), tmp);
	(stk_from->size)--;
	(stk_to->size)++;
	return (1);
}

int	swap(t_stk *stk)
{
	t_list	*tmp;

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
	swap(stk_a);
	swap(stk_b);
	return (1);
}
