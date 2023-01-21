/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:28:15 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 14:48:55 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
}

void	ft_puterr(int err)
{
	write(2, "Error: ", 7);
	if (err == 0)
		write(2, "Invalid Argument", 16);
	write(2, "\n", 1);
}
