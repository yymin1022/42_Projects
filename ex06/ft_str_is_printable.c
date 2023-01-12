/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:27:07 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/12 22:39:13 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		if ((int)(*(str + idx)) >= 9 && (int)(*(str + idx)) <= 13)
			idx++;
		else if ((int)(*(str + idx)) >= 32 && (int)(*(str + idx)) <= 126)
			idx++;
		else
			return (0);
	}
	return (1);
}
