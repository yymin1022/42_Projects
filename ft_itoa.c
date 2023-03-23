/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:34:42 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/23 14:51:46 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len(int n, int *is_neg)
{
	size_t	len;

	if (!n)
		return (1);
	len = 0;
	if (n < 0)
	{
		*is_neg = 1;
		len++;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	get_str(int n, int is_neg, char *res)
{
	size_t	idx;

	idx = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			idx++;
			*res = '8';
			n /= 10;
		}
		n *= -1;
	}
	while (n != 0)
	{
		*(res + idx) = n % 10 + '0';
		n /= 10;
		idx++;
	}
	if (is_neg)
	{
		*(res + idx) = '-';
		idx++;
	}
	*(res + idx) = '\0';
}

void	rev_str(char *str)
{
	char	c;
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(str);
	while (idx < len / 2)
	{
		c = *(str + idx);
		*(str + idx) = *(str + len - idx - 1);
		*(str + len - idx - 1) = c;
		idx++;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		is_neg;
	size_t	len;

	is_neg = 0;
	len = get_len(n, &is_neg);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	if (!n)
	{
		*res = '0';
		*(res + 1) = '\0';
		return (res);
	}
	get_str(n, is_neg, res);
	rev_str(res);
	return (res);
}
