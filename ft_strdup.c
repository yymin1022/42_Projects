/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:14:29 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/17 14:22:27 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		idx;
	int		src_size;

	src_size = 0;
	while (*(s1 + src_size))
		src_size++;
	res = (char *)malloc(src_size + 1);
	idx = 0;
	while (idx < src_size)
	{
		*(res + idx) = *(s1 + idx);
		idx++;
	}
	*(res + idx) = '\0';
	return (res);
}
