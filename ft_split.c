/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:12:05 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/21 19:15:35 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

int	ft_get_str_cnt(char const *str, char c)
{
	int	cnt;
	int	idx;

	cnt = 0;
	idx = 0;
	while (*(str + idx))
	{
		while (*(str + idx) && ft_check_sep(*(str + idx), c))
		{
			idx++;
		}
		if (*(str + idx))
			cnt++;
		while (*(str + idx) && !ft_check_sep(*(str + idx), c))
		{
			idx++;
		}
	}
	return (cnt);
}

char	*ft_get_str(char const *str, char c)
{
	char	*tmp;
	int		idx;
	int		len;

	len = 0;
	while (*(str + len) && !ft_check_sep(*(str + len), c))
		len++;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	idx = 0;
	while (idx < len)
	{
		*(tmp + idx) = *(str + idx);
		idx++;
	}
	*(tmp + idx) = '\0';
	return (tmp);
}

char	**free_mem(char **res, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		free(*(res + idx));
		idx++;
	}
	free(res);
	return (0);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		idx;
	int		result_cnt;
	int		result_idx;

	result_cnt = ft_get_str_cnt(str, c);
	result = (char **)malloc(sizeof(char *) * (result_cnt + 1));
	if (!result)
		return (0);
	idx = 0;
	result_idx = 0;
	while (result_cnt > 0 && *(str + idx))
	{
		while (*(str + idx) && ft_check_sep(*(str + idx), c))
			idx++;
		if (*(str + idx) != '\0')
		{
			*(result + result_idx) = ft_get_str(str + idx, c);
			if (!*(result + result_idx))
				return (free_mem(result, result_idx));
			result_idx++;
		}
		while (*(str + idx) && !ft_check_sep(*(str + idx), c))
			idx++;
	}
	*(result + result_idx) = 0;
	return (result);
}
