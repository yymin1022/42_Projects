/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:26:34 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/23 18:34:40 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*res_next;

	res = 0;
	while (lst->next)
	{
		res_next = ft_lstnew(f(lst->content));
		if (!res_next)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		ft_lstadd_back(&res, res_next);
		lst = lst->next;
	}
	res_next = 0;
	return (res);
}
