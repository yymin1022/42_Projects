/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:48:07 by youngcch          #+#    #+#             */
/*   Updated: 2023/01/14 14:50:30 by youngcch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);

void	print_error(char c)
{
	ft_putchar('E');
	ft_putchar('r');
	ft_putchar('r');
	ft_putchar(':');
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(' ');
	ft_putchar('i');
	ft_putchar('s');
	ft_putchar(' ');
	ft_putchar('N');
	ft_putchar('e');
	ft_putchar('g');
	ft_putchar('a');
	ft_putchar('t');
	ft_putchar('i');
	ft_putchar('v');
	ft_putchar('e');
	ft_putchar('\n');
}

int	check_error(int x, int y)
{
	int	flag;

	flag = 0;
	if (x < 0)
	{
		flag = 1;
		print_error('x');
	}
	if (y < 0)
	{
		flag = 1;
		print_error('y');
	}
	if (flag)
		return (-1);
	return (0);
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	if (check_error(x, y) == -1)
		return ;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if ((i == 0 && j == 0) || (i == y - 1 && j == x - 1 && i > 0))
				ft_putchar('A');
			else if ((i == 0 && j == x - 1) || (i == y - 1 && j == 0))
				ft_putchar('C');
			else if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
