/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:45:19 by yonyoo            #+#    #+#             */
/*   Updated: 2023/07/17 18:21:47 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(va_list ap, const char format, int *cnt)
{
	if (format == 'c' && print_char(va_arg(ap, int), cnt) < 0)
		return (-1);
	else if (format == 's' && print_str(va_arg(ap, char *), cnt) < 0)
		return (-1);
	else if (format == 'p' && print_ptr(va_arg(ap, void *), cnt) < 0)
		return (-1);
	else if ((format == 'd' || format == 'i')
		&& print_dec(va_arg(ap, int), cnt) < 0)
		return (-1);
	else if (format == 'u' && print_u_dec(va_arg(ap, unsigned int), cnt) < 0)
		return (-1);
	else if (format == 'x' && print_hex_lower(va_arg(ap, int), cnt) < 0)
		return (-1);
	else if (format == 'X' && print_hex_upper(va_arg(ap, int), cnt) < 0)
		return (-1);
	else if (format == '%' && print_char('%', cnt) < 0)
		return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		cnt;
	int		idx;
	va_list	ap;

	cnt = 0;
	idx = 0;
	va_start(ap, str);
	while (*(str + idx))
	{
		if (*(str + idx) == '%')
			print_format(ap, *(str + ++idx), &cnt);
		else
			print_char(*(str + idx), &cnt);
		idx++;
	}
	va_end(ap);
	return (cnt);
}
