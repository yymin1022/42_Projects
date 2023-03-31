/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:14:29 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/23 11:44:15 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	idx;

	res = (char *)malloc(ft_strlen(s1) + 1);
	if (!res)
		return (0);
	idx = 0;
	while (*(s1 + idx))
	{
		*(res + idx) = *(s1 + idx);
		idx++;
	}
	*(res + idx) = '\0';
	return (res);
}
