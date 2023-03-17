/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:58:07 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/17 16:02:49 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		neg_flag;
	int		res;

	i = 0;
	while (*(str + i) && (((char)*(str + i) >= 9 && (char)*(str + i) <= 13)
			|| ((char)*(str + i) == 32)))
		i++;
	neg_flag = 1;
	if (*(str + i) == '-')
	{
		i++;
		neg_flag = -1;
	}
	else if (*(str + i) == '+')
		i++;
	res = 0;
	while (*(str + i))
	{
		if (*(str + i) < 48 || *(str + i) > 57)
			break ;
		res = res * 10 + *(str + i) - 48;
		i++;
	}
	return (res * neg_flag);
}
