/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:41:45 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/17 18:39:42 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*res1;
	unsigned char	*res2;
	size_t			i;

	if (!n)
		return (0);
	i = 0;
	res1 = (unsigned char *)s1;
	res2 = (unsigned char *)s2;
	while (i < n)
	{
		if (*(res1 + i) != *(res2 + i))
			return (*(res1 + i) - *(res2 + i));
		i++;
	}
	return (0);
}
