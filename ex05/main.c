/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:18:28 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/26 21:23:15 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int	main(int argc, char **argv)
{
	int	num1;
	int	num2;
	int			op;

	if (argc != 4)
		return (-1);
	op = get_op(*(argv + 2));
	if (op == -1)
	{
		ft_putnbr(0);
		return (-1);
	}
	num1 = get_num(*(argv + 1));
	num2 = get_num(*(argv + 3));
	if ((op == 3 || op == 4) && num2 == 0)
	{
		if (op == 3)
			ft_putstr("Stop : division by zero");
		if (op == 4)
			ft_putstr("Stop : modulo by zero");
		return (-1);
	}
	ft_putnbr(calc_num(num1, num2, op));
	return (0);
}
