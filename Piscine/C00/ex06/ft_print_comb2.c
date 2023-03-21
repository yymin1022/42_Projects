/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:09:13 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/12 18:39:03 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_num(int num)
{
	char	tmp;

	if (num < 10)
	{
		tmp = (char)(num + '0');
		write(1, "0", 1);
		write(1, &tmp, 1);
	}
	else
	{
		tmp = (char)(num / 10 + '0');
		write(1, &tmp, 1);
		tmp = (char)(num % 10 + '0');
		write(1, &tmp, 1);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print_num(a);
			write(1, " ", 1);
			ft_print_num(b);
			if (a != 98 || b != 99)
			{
				write(1, ", ", 2);
			}
			b++;
		}
		a++;
	}
}
