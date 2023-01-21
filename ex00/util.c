/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:38:19 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 14:29:16 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

int	check_arg(char *arg)
{
	int	idx;

	idx = 0;
	while (arg[idx])
	{
		if (idx % 2 == 0)
		{
			if (!(arg[idx] >= '1' && arg[idx] <= '4'))
				return (0);
		}
		else
		{
			if (arg[idx] != ' ')
				return (0);
		}
		idx++;
	}
	return (1);
}

void	print_err(int err)
{
	write(2, "Error: ", 7);
	if (err == 0)
		write(2, "Invalid Argument", 16);
	write(2, "\n", 1);
}
