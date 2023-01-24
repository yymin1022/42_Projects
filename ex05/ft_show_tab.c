/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:11:51 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/24 21:21:43 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putnbr(int n)
{
	char	tmp;

	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
		{
			write(1, "2", 1);
			n = -147483648;
		}
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		tmp = n + '0';
		write(1, &tmp, 1);
	}
}

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		write(1, str + idx, 1);
		idx++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	idx;

	idx = 0;
	while ((par + idx)->str)
	{
		ft_putstr((par + idx)->str);
		ft_putstr("\n");
		ft_putnbr((par + idx)->size);
		ft_putstr("\n");
		ft_putstr((par + idx)->copy);
		ft_putstr("\n");
		idx++;
	}
}
