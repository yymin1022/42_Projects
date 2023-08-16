/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 06:00:32 by yonyoo            #+#    #+#             */
/*   Updated: 2023/08/12 17:42:34 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	idx;

	if(!s1)
		return (NULL);
	res = (char *)malloc(ft_strlen(s1) + 1);
	if (!res)
		return (NULL);
	idx = 0;
	while (*(s1 + idx))
	{
		*(res + idx) = *(s1 + idx);
		idx++;
	}
	*(res + idx) = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	size1;
	size_t	size2;

	if(!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(res + i) = *(s1 + i);
		i++;
	}
	i = 0;
	while (*(s2 + i))
	{
		*(res + i + size1) = *(s2 + i);
		i++;
	}
	*(res + i + size1) = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}
