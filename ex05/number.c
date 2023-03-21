/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:23:32 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/28 11:06:33 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

void	ft_putnbr(long long num)
{
	char		result[100];
	int			idx;
	int			is_minus;

	is_minus = 0;
	if (num < 0)
	{
		is_minus = 1;
		num *= -1;
	}
	idx = 0;
	while (num >= 10)
	{
		*(result + idx) = (num % 10) + '0';
		num /= 10;
		idx++;
	}
	*(result + idx) = (num % 10) + '0';
	if (is_minus)
	{
		*(result + idx + 1) = '-';
		idx++;
	}
	*(result + idx + 1) = '\0';
	ft_putstr(ft_strrev(result));
}

int	calc_operator(int num1, int num2, int (*op)(int, int))
{
	return (op(num1, num2));
}

int	calc_num(int num1, int num2, int op)
{
	if (op == 0)
		return (calc_operator(num1, num2, &plus));
	else if (op == 1)
		return (calc_operator(num1, num2, &minus));
	else if (op == 2)
		return (calc_operator(num1, num2, &multiply));
	else if (op == 3)
		return (calc_operator(num1, num2, &division));
	return (calc_operator(num1, num2, &modulo));
}

int	get_num(char *str)
{
	int	idx;
	int	sign;
	int	result;

	idx = 0;
	while ((*(str + idx) >= 9 && *(str + idx) <= 13) || *(str + idx) == ' ')
		idx++;
	sign = 1;
	while (*(str + idx) == '+' || *(str + idx) == '-')
	{
		if (*(str + idx) == '-')
			sign *= -1;
		idx++;
	}
	result = 0;
	while (*(str + idx) && *(str + idx) >= '0' && *(str + idx) <= '9')
	{
		result = result * 10 + (*(str + idx) - '0');
		idx++;
	}
	return (result * sign);
}

int	get_op(char *str)
{
	if (ft_strlen(str) != 1)
		return (-1);
	if (*str == '+')
		return (0);
	else if (*str == '-')
		return (1);
	else if (*str == '*')
		return (2);
	else if (*str == '/')
		return (3);
	else if (*str == '%')
		return (4);
	return (-1);
}
