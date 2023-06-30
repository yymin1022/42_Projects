/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 01:41:25 by yonyoo            #+#    #+#             */
/*   Updated: 2023/07/01 02:12:24 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, int *cnt)
{
	ft_putchar_fd(c, 1);
	(*cnt)++;
}

void	print_str(char *str, int *cnt)
{
	ft_putstr_fd(str, 1);
	(*cnt) += ft_strlen(str);
}

static void	print_mem(unsigned long long mem, int *cnt)
{
	if (mem < 16)
		print_char("0123456789abcdef"[mem], cnt);
	else
	{
		print_mem(mem / 16, cnt);
		print_mem(mem % 16, cnt);
	}
}

void	print_ptr(void *ptr, int *cnt)
{
	print_str("0x", cnt);
	print_mem((unsigned long long)ptr, cnt);
}
