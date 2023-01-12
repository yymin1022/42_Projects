/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:26:47 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/12 12:35:50 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		idx;
	int		tmp;

	idx = 0;
	while (idx < size / 2)
	{
		tmp = *(tab + idx);
		*(tab + idx) = *(tab + size - idx - 1);
		*(tab + size - idx - 1) = tmp;
		idx++;
	}
}
