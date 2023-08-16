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

void	*ft_free(char **target)
{
	if (!(*target))
		return (NULL);
	free(*target);
	*target = NULL;
	return (*target);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	ssize_t	idx;

	if (!s1)
		return (NULL);
	res = (char *)malloc(ft_strlen(s1) + 1);
	if (!res)
		return (NULL);
	idx = -1;
	while (s1[++idx])
		res[idx] = s1[idx];
	res[idx] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	ssize_t	i;
	ssize_t	size1;
	ssize_t	size2;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	i = -1;
	while (s2[++i])
		res[i + size1] = s2[i];
	res[i + size1] = '\0';
	return (res);
}

ssize_t	ft_strlen(const char *s)
{
	ssize_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
