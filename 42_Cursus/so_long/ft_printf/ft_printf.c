/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:45:19 by yonyoo            #+#    #+#             */
/*   Updated: 2023/07/18 01:59:22 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(va_list ap, const char format, int *cnt)
{
	if (format == 'c')
		return (print_char(va_arg(ap, int), cnt));
	else if (format == 's')
		return (print_str(va_arg(ap, char *), cnt));
	else if (format == 'p')
		return (print_ptr(va_arg(ap, void *), cnt));
	else if (format == 'd' || format == 'i')
		return (print_dec(va_arg(ap, int), cnt));
	else if (format == 'u')
		return (print_u_dec(va_arg(ap, unsigned int), cnt));
	else if (format == 'x')
		return (print_hex_lower(va_arg(ap, int), cnt));
	else if (format == 'X')
		return (print_hex_upper(va_arg(ap, int), cnt));
	else if (format == '%')
		return (print_char('%', cnt));
	else
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
		{
			if (print_format(ap, *(str + ++idx), &cnt) < 0)
				return (-1);
		}
		else
		{
			if (print_char(*(str + idx), &cnt) < 0)
				return (-1);
		}
		idx++;
	}
	va_end(ap);
	return (cnt);
}
