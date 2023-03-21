/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:58:11 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/23 10:40:12 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(int n)
{
	char	tmp;
	int		a;
	int		b;

	a = n / 16;
	tmp = a + '0';
	if (a > 9)
		tmp = a - 10 + 'a';
	write(1, "\\", 1);
	write(1, &tmp, 1);
	b = n % 16;
	tmp = b + '0';
	if (b > 9)
		tmp = b - 10 + 'a';
	write(1, &tmp, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				idx;
	unsigned char	*str2;

	idx = 0;
	str2 = (unsigned char *)str;
	while (*(str2 + idx))
	{
		if (*(str2 + idx) >= 32 && *(str2 + idx) <= 126)
			write(1, str2 + idx, 1);
		else
			ft_print_hex(*(str2 + idx));
		idx++;
	}
}
