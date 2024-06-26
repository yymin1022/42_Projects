/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 06:00:32 by yonyoo            #+#    #+#             */
/*   Updated: 2023/10/28 16:14:41 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free2(char **target)
{
	if (!(*target))
		return (NULL);
	free(*target);
	*target = NULL;
	return (*target);
}

char	*ft_strdup2(char *s1)
{
	char	*res;
	ssize_t	idx;

	if (!s1)
		return (NULL);
	res = (char *)malloc(ft_strlen2(s1) + 1);
	if (!res)
		return (NULL);
	idx = -1;
	while (s1[++idx])
		res[idx] = s1[idx];
	res[idx] = '\0';
	return (res);
}

char	*ft_strjoin2(char **s1, char *s2)
{
	char	*res;
	ssize_t	i;
	ssize_t	size1;
	ssize_t	size2;

	if (!(*s1) || !s2)
		return (ft_free2(s1));
	size1 = ft_strlen2(*s1);
	size2 = ft_strlen2(s2);
	res = (char *)malloc(size1 + size2 + 1);
	if (!res)
		return (ft_free2(s1));
	i = -1;
	while ((*s1)[++i])
		res[i] = (*s1)[i];
	i = -1;
	while (s2[++i])
		res[i + size1] = s2[i];
	res[i + size1] = '\0';
	ft_free2(s1);
	return (res);
}

ssize_t	ft_strlen2(char *s)
{
	ssize_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}
