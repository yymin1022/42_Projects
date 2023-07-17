/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 01:41:25 by yonyoo            #+#    #+#             */
/*   Updated: 2023/07/17 18:19:51 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, int *cnt)
{
	(*cnt)++;
	return (write(1, &c, 1));
}

int	print_str(char *str, int *cnt)
{
	int	idx;

	if (str == 0)
		return (print_str("(null)", cnt));
	idx = 0;
	while (*(str + idx))
	{
		if (print_char(*(str + idx), cnt) < 0)
			return (-1);
		idx++;
	}
	return (0);
}

static int	print_mem(unsigned long long mem, int *cnt)
{
	if (mem < 16)
		return (print_char("0123456789abcdef"[mem], cnt));
	else
		if (print_mem(mem / 16, cnt) < 0 || print_mem(mem % 16, cnt) < 0)
			return (-1);
	return (0);
}

int	print_ptr(void *ptr, int *cnt)
{
	if (print_str("0x", cnt) < 0 || print_mem((unsigned long long)ptr, cnt) < 0)
		return (-1);
	return (0);
}
