/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_num.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 01:40:23 by yonyoo            #+#    #+#             */
/*   Updated: 2023/07/01 01:46:35 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_dec(int num, int *cnt)
{
	long long	n;

	n = num;
	if(n < 0){
		print_char('-', cnt);
		n *= -1;
	}
	print_u_dec(num, cnt);
}

static void	print_u_dec(unsigned int num, int *cnt)
{
	if (num < 10)
		print_char(num + '0', cnt);
	else
	{
		print_u_dec(num / 10, cnt);
		print_u_dec(num % 10, cnt);
	}
}

static void	print_hex_lower(int num, int *cnt)
{
	if (num < 16)
		print_char("0123456789abcdef"[num], cnt);
	else
	{
		print_hex_lower(num / 16, cnt);
		print_hex_lower(num % 16, cnt);
	}
}

static void	print_hex_upper(int num, int *cnt)
{
	if (num < 16)
		print_char("0123456789ABCDEF"[num], cnt);
	else
	{
		print_hex_lower(num / 16, cnt);
		print_hex_lower(num % 16, cnt);
	}
}
