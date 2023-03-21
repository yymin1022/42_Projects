/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:44:49 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/17 15:35:34 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_base(char *base, int *base_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(base + i))
	{
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		j = i + 1;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	*base_len = i;
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long long nbr, char *base, int base_len)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr, base, base_len);
	}
	else if (nbr >= base_len)
	{
		ft_putnbr(nbr / base_len, base, base_len);
		ft_putnbr(nbr % base_len, base, base_len);
	}
	else
	{
		ft_putchar(*(base + nbr));
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_len;
	long long	long_nbr;

	base_len = 0;
	if (!ft_check_base(base, &base_len))
		return ;
	long_nbr = (long long)nbr;
	ft_putnbr(long_nbr, base, base_len);
}
