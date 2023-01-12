/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:58:37 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/12 22:26:11 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		if (*(str + idx) >= 'A' && *(str + idx) <= 'Z')
			idx++;
		else
			return (0);
	}
	return (1);
}
