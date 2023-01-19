/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:34:26 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/19 21:51:48 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_check_heading(char *str, int *idx, int *sign)
{
	while (*(str + *idx))
	{
		if ((*(str + *idx) >= 9 && (*(str + *idx) <= 13))
			|| *(str + *idx) == 32)
			(*idx)++;
		else
			break ;
	}
	while (*(str + *idx))
	{
		if (*(str + *idx) == '-')
		{
			*sign = (*sign) * -1;
			(*idx)++;
		}
		else if (*(str + *idx) == '+')
			(*idx)++;
		else
			break ;
	}
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (*(base + i))
	{
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		j = i + 1;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	ft_get_base(char cur, char *base)
{
	int	idx;

	idx = 0;
	while (*(base + idx))
	{
		if (*(base + idx) == cur)
			return (idx);
		idx++;
	}
	return (-1);
}

void	ft_rev_str(char *str)
{
	char	tmp;
	int		idx;
	int		size;

	size = 0;
	while (*(str + size))
		size++;
	idx = 0;
	while (idx < size / 2)
	{
		tmp = *(str + idx);
		*(str + idx) = *(str + size - idx - 1);
		*(str + size - idx - 1) = tmp;
		idx++;
	}
}
