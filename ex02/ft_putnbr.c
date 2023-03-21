/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:37:11 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/16 20:06:45 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char nb)
{
	write(1, &nb, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_print('-');
		if (nb == -2147483648)
		{
			ft_print('2');
			nb = -147483648;
		}
		ft_putnbr(-nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_print(nb + '0');
	}
}
