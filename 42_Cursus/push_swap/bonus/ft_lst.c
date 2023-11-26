/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:42:51 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/26 19:59:16 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!(*lst) && new)
		*lst = new;
	else if (*lst && new)
		ft_lstlast(*lst)->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstlast_prev(t_list *lst)
{
	if (!lst)
		return (0);
	if (!(lst->next))
		return (0);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	sort_finish(t_stk *stk)
{
	int		i;
	int		j;
	int		prev;
	t_list	*tmp;

	i = 1;
	prev = stk->top->num;
	tmp = stk->top->next;
	while (i < stk->size)
	{
		if (tmp->num < prev)
			break ;
		tmp = tmp->next;
		i++;
	}
	j = 0;
	if (i < stk->size / 2)
		while (j++ < i)
			rotate('a', stk);
	else
		while (j++ < stk->size - i)
			r_rotate('a', stk);
}
