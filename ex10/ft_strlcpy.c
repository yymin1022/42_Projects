/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:46:45 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/15 21:25:47 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	src_size;

	src_size = 0;
	while (*(src + src_size))
	{
		src_size++;
	}
	if (size > 0)
	{
		idx = 0;
		while (*(src + idx) && idx < size - 1)
		{
			*(dest + idx) = *(src + idx);
			idx++;
		}
		*(dest + idx) = '\0';
	}
	return (src_size);
}
