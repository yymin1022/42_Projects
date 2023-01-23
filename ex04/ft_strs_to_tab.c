/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:33:20 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/23 14:23:43 by yonyoo           ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	char	*new_str;
	int		idx;
	int		src_size;

	src_size = 0;
	while (*(src + src_size))
		src_size++;
	new_str = (char *)malloc(sizeof(char) * (src_size + 1));
	idx = 0;
	while (idx < src_size)
	{
		*(new_str + idx) = *(src + idx);
		idx++;
	}
	*(new_str + idx) = '\0';
	return (new_str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			idx;
	int			len;
	t_stock_str	*arr;

	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (arr == 0)
		return (0);
	idx = 0;
	while (idx < ac)
	{
		len = ft_strlen(*(av + idx));
		(arr + idx)->size = ft_strlen(*(av + idx));
		(arr + idx)->str = *(av + idx);
		(arr + idx)->copy = ft_strdup(*(av + idx));
		idx++;
	}
	(arr + idx)->str = "\0";
	return (arr);
}
