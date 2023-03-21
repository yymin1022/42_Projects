/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:36:49 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/18 13:01:08 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_heading(char *str, int *idx, int *sign)
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

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (*(base + i))
	{
		if ((*(base + i) >= 9 && *(base + i) <= 13)
			|| *(base + i) == 32
			|| *(base + i) == '+' || *(base + i) == '-')
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

int	get_base(char cur, char *base)
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

int	ft_atoi_base(char *str, char *base)
{
	int	idx;
	int	len_base;
	int	result;
	int	sign;
	int	tmp;

	len_base = check_base(base);
	if (!len_base)
		return (0);
	idx = 0;
	sign = 1;
	check_heading(str, &idx, &sign);
	result = 0;
	while (*(str + idx))
	{
		tmp = get_base(*(str + idx), base);
		if (tmp == -1)
			break ;
		result *= len_base;
		result += tmp;
		idx++;
	}
	return (result * sign);
}
