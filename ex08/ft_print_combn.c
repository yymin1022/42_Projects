/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:40:16 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/13 20:46:33 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int *num, int n)
{
	char	tmp;
	int		idx;

	idx = 1;
	while (idx < n)
	{
		if (*(num + idx) <= *(num + idx - 1))
			return ;
		idx++;
	}
	idx = 0;
	while (idx < n)
	{
		tmp = *(num + idx) + '0';
		write(1, &tmp, 1);
		idx++;
	}
	if (*num < 10 - n)
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	int	idx;
	int	num[10];

	idx = 0;
	while (idx < n)
	{
		num[idx] = idx;
		idx++;
	}
	while (num[0] <= 10 - n)
	{
		print_num(num, n);
		idx = n - 1;
		num[idx]++;
		while (idx > 0)
		{
			if (num[idx] > 9)
			{
				num[idx] = 0;
				num[idx - 1]++;
			}
			idx--;
		}
	}
}
