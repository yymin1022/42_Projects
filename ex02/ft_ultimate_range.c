/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:44:49 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/19 11:30:43 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	idx;
	int	*tmp;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}

	idx = 0;
	tmp = (int *)malloc(sizeof(int) * (max - min));
	if (tmp == 0)
		return (-1);
	while (idx < (max - min))
	{
		*(tmp + idx) = min + idx;
		idx++;
	}
	*range = tmp;
	return (max - min);
}
