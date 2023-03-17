/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:16:35 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/17 16:55:14 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{	
	size_t			i;

	if (!dst && !src)
		return (dst);
	i = 0;
	while (i < len)
	{
		if ((unsigned char *)src < (unsigned char *)dst)
			*((unsigned char *)dst + len - i - 1)
				= *((unsigned char *)src + len - i - 1);
		else
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}
