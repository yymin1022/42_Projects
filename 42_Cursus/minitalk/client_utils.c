/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:09:38 by yonyoo            #+#    #+#             */
/*   Updated: 2023/10/08 19:21:40 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_atoi(char *str)
{
	int	idx;
	int	res;

	idx = 0;
	res = 0;
	while (str[idx])
	{
		if (str[idx] >= '0' && str[idx] <= '9')
			res = res * 10 + str[idx] - '0';
		else
			return (-1);
		if (res > 99998)
			return (-1);
		idx++;
	}
	return (res);
}

void	ft_put_str(char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
}

char	*ft_strjoin(char *str, char *append)
{
	char	*res;
	size_t	idx;
	size_t	size;

	size = ft_strlen(str);
	res = (char *)malloc(size + ft_strlen(append) + 1);
	if (!res)
		return (NULL);
	idx = 0;
	while (str[idx])
	{
		res[idx] = str[idx];
		idx++;
	}
	idx = 0;
	while (append[idx])
	{
		res[size + idx] = append[idx];
		idx++;
	}
	res[size + idx] = '\0';
	return (res);
}

size_t	ft_strlen(char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}
