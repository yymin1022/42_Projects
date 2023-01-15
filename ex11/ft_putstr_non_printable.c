/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:58:11 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/15 13:57:01 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(int n)
{
	char	tmp;
	int		a;
	int		b;

	a = n / 16;
	b = n % 16;
	tmp = a + '0';
	write(1, "\\", 1);
	write(1, &tmp, 1);
	if (b < 9)
		tmp = b + '0';
	else
		tmp = b + 'a' - 10;
	write(1, &tmp, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		if (*(str + idx) >= 32 && *(str + idx) <= 126)
			write(1, str + idx, 1);
		else
			ft_print_hex(*(str + idx));
		idx++;
	}
}
