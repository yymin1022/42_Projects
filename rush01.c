/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebjung <jaebjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:58:49 by jaebjung          #+#    #+#             */
/*   Updated: 2023/01/14 15:20:55 by jaebjung         ###   ########.fr       */
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

	if (check_error(x, y) == -1)
		return ;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if ((!i && !j) || (i == y - 1 && j == x - 1 && i > 0 && j > 0))
				ft_putchar('/');
			else if ((!i && j == x - 1) || (i == y - 1 && !j))
				ft_putchar('\\');
			else if ((!i || i == y - 1) || (!j || j == x - 1))
				ft_putchar('*');
			else
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
