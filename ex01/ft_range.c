/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:23:27 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/18 22:28:31 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	idx;
	int	*arr;

	arr = malloc(sizeof(int) * (max - min + 1));
	idx = 0;
	while (idx <= max - min)
	{
		*(arr + idx) = min + idx;
		idx++;
	}
	return (arr);
}
