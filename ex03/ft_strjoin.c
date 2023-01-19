/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:54:02 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/19 16:36:54 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	idx;
	int	size;

	idx = 0;
	size = 0;
	while (*(dest + size))
		size++;
	while (*(src + idx))
	{
		*(dest + size + idx) = *(src + idx);
		idx++;
	}
	*(dest + size + idx) = '\0';
	return (dest);
}

char	*ft_make_str(char *result, int size, char **strs, char *sep)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		result = ft_strcat(result, *(strs + idx));
		if (idx < size - 1)
			result = ft_strcat(result, sep);
		idx++;
	}
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		idx;
	int		mem_size;

	if (size == 0)
	{
		result = (char *)malloc(sizeof(char));
		*(result) = '\0';
		return (result);
	}
	idx = 0;
	mem_size = 0;
	while (idx < size)
	{
		mem_size += ft_strlen(*(strs + idx));
		idx++;
	}
	mem_size += ft_strlen(sep) * (size - 1);
	result = (char *)malloc(sizeof(char) * mem_size + 1);
	if (result == 0)
		return (0);
	result = ft_make_str(result, size, strs, sep);
	return (result);
}
