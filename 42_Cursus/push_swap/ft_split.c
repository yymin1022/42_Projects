/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:12:05 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/26 15:23:15 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_str_cnt(char const *str, char c)
{
	size_t	cnt;
	size_t	idx;

	cnt = 0;
	idx = 0;
	while (*(str + idx))
	{
		while (*(str + idx) && *(str + idx) == c)
			idx++;
		if (*(str + idx))
			cnt++;
		while (*(str + idx) && *(str + idx) != c)
			idx++;
	}
	return (cnt);
}

static char	*ft_get_str(char const *str, char c, size_t *orig_idx)
{
	char	*tmp;
	size_t	idx;
	size_t	len;

	len = 0;
	while (*(str + len) && *(str + len) != c)
		len++;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		exit_err();
	idx = 0;
	while (idx < len)
	{
		*(tmp + idx) = *(str + idx);
		idx++;
		(*orig_idx)++;
	}
	*(tmp + idx) = '\0';
	return (tmp);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	size_t	idx;
	size_t	result_cnt;
	size_t	result_idx;

	result_cnt = ft_get_str_cnt(str, c);
	result = (char **)malloc(sizeof(char *) * (result_cnt + 1));
	if (!result)
		exit_err();
	idx = 0;
	result_idx = 0;
	while (result_cnt > 0 && *(str + idx))
	{
		while (*(str + idx) && *(str + idx) == c)
			idx++;
		if (*(str + idx) != '\0')
		{
			*(result + result_idx) = ft_get_str(str + idx, c, &idx);
			if (!*(result + result_idx))
				exit_err();
			result_idx++;
		}
	}
	*(result + result_idx) = 0;
	return (result);
}
