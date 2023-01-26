/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:30:41 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/26 18:17:03 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
		idx++;
	return (idx);
}

void	ft_strrev(char *str)
{
	char	tmp;
	int		idx;
	int		size;

	size = 0;
	while (*(str + size))
		size++;
	idx = 0;
	while (idx < size / 2)
	{
		tmp = *(str + idx);
		*(str + idx) = *(str + size - idx - 1);
		*(str + size - idx - 1) = tmp;
		idx++;
	}
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
