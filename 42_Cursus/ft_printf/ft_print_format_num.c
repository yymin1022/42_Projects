/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_num.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 01:40:23 by yonyoo            #+#    #+#             */
/*   Updated: 2023/07/17 18:21:33 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_dec(int num, int *cnt)
{
	long long	n;

	n = num;
	if (n < 0)
	{
		if (print_char('-', cnt) < 0)
			return (-1);
		n *= -1;
	}
	return (print_u_dec(n, cnt));
}

int	print_u_dec(unsigned int num, int *cnt)
{
	if (num < 10)
		return (print_char(num + '0', cnt));
	else
		if (print_u_dec(num / 10, cnt) < 0
			|| print_u_dec(num % 10, cnt) < 0)
			return (-1);
	return (0);
}

int	print_hex_lower(unsigned int num, int *cnt)
{
	if (num < 16)
		return (print_char("0123456789abcdef"[num], cnt));
	else
		if (print_hex_lower(num / 16, cnt) < 0
			|| print_hex_lower(num % 16, cnt) < 0)
			return (-1);
	return (0);
}

int	print_hex_upper(unsigned int num, int *cnt)
{
	if (num < 16)
		return (print_char("0123456789ABCDEF"[num], cnt));
	else
		if (print_hex_upper(num / 16, cnt) < 0
			|| print_hex_upper(num % 16, cnt) < 0)
			return (-1);
	return (0);
}
