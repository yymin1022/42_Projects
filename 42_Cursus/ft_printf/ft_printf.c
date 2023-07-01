/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:45:19 by yonyoo            #+#    #+#             */
/*   Updated: 2023/07/01 21:02:47 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_format(va_list ap, const char format, int *cnt)
{
	if (format == 'c')
		print_char(va_arg(ap, int), cnt);
	else if (format == 's')
		print_str(va_arg(ap, char *), cnt);
	else if (format == 'p')
		print_ptr(va_arg(ap, void *), cnt);
	else if (format == 'd' || format == 'i')
		print_dec(va_arg(ap, int), cnt);
	else if (format == 'u')
		print_u_dec(va_arg(ap, unsigned int), cnt);
	else if (format == 'x')
		print_hex_lower(va_arg(ap, int), cnt);
	else if (format == 'X')
		print_hex_upper(va_arg(ap, int), cnt);
	else if (format == '%')
		print_char('%', cnt);
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
