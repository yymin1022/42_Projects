/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:12:05 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/19 19:52:45 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_sep(char c, char *charset)
{
	int	idx;

	idx = 0;
	while (*(charset + idx))
	{
		if (*(charset + idx) == c)
			return (1);
		idx++;
	}
	return (0);
}

int	ft_get_str_cnt(char *str, char *charset)
{
	int	cnt;
	int	idx;

	cnt = 0;
	idx = 0;
	while (*(str + idx))
	{
		while (*(str + idx) && ft_check_sep(*(str + idx), charset))
		{
			idx++;
		}
		if (*(str + idx))
			cnt++;
		while (*(str + idx) && !ft_check_sep(*(str + idx), charset))
		{
			idx++;
		}
	}
	return (cnt);
}

char	*ft_get_str(char *str, char *charset)
{
	char	*tmp;
	int		idx;
	int		len;

	len = 0;
	while (*(str + len) && !ft_check_sep(*(str + len), charset))
		len++;
	tmp = (char *)malloc(sizeof(char) * len);
	idx = 0;
	while (idx < len)
	{
		*(tmp + idx) = *(str + idx);
		idx++;
	}
	*(tmp + idx) = '\0';
	return (tmp);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		idx;
	int		result_cnt;
	int		result_idx;

	result_cnt = ft_get_str_cnt(str, charset);
	result = (char **)malloc(sizeof(char *) * (result_cnt + 1));
	idx = 0;
	result_idx = 0;
	while (result_cnt > 0 && *(str + idx))
	{
		while (*(str + idx) && ft_check_sep(*(str + idx), charset))
			idx++;
		if (*(str + idx) != '\0')
		{
			*(result + result_idx) = ft_get_str(str + idx, charset);
			result_idx++;
		}
		while (*(str + idx) && !ft_check_sep(*(str + idx), charset))
			idx++;
	}
	*(result + result_idx) = 0;
	return (result);
}
