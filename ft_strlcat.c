/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:51:51 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/21 20:19:04 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (*(src + i) && dst_size + i < size - 1)
		{
			*(dst + dst_size + i) = *(src + i);
			i++;
		}
		*(dst + dst_size + i) = '\0';
	}
	if (dst_size > size)
		return (src_size + size);
	return (dst_size + src_size);
}
