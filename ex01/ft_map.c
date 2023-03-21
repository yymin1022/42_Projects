/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:59:26 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/25 15:06:21 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*arr;
	int	idx;

	arr = (int *)malloc(sizeof(int) * length);
	idx = 0;
	while (idx < length)
	{
		*(arr + idx) = f(*(tab + idx));
		idx++;
	}
	return (arr);
}
