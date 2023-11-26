/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:58:07 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/25 10:51:31 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_idx(int *arr, int size)
{
	int	i;
	int	min_idx;
	int	min_val;

	i = 0;
	min_val = 2147483647;
	while (i < size)
	{
		if (arr[i] < min_val)
		{
			min_idx = i;
			min_val = arr[i];
		}
		i++;
	}
	return (min_idx);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

long long	ft_atoll(const char *str)
{
	int			neg_flag;
	size_t		i;
	long long	res;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13)
			|| (str[i] == 32)))
		i++;
	neg_flag = 1;
	if (str[i] == '-')
		neg_flag = -1;
	i += (str[i] == '+' || str[i] == '-');
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg_flag);
}
