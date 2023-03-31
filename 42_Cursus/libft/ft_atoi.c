/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:58:07 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/23 11:39:07 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	long	neg_flag;
	long	res;

	i = 0;
	while (*(str + i) && ((*(str + i) >= 9 && *(str + i) <= 13)
			|| (*(str + i) == 32)))
		i++;
	neg_flag = 1;
	if (*(str + i) == '-')
		neg_flag = -1;
	i += (*(str + i) == '+' || *(str + i) == '-');
	res = 0;
	while (*(str + i))
	{
		if (*(str + i) < 48 || *(str + i) > 57)
			break ;
		res = res * 10 + *(str + i) - 48;
		i++;
	}
	return ((int)(res * neg_flag));
}
