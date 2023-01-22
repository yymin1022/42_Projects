/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:40:40 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/22 11:29:00 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_data(int *result)
{
	char	tmp;
	int		idx;

	idx = 0;
	while (idx < 10)
	{
		tmp = *(result + idx) + '0';
		write(1, &tmp, 1);
		idx++;
	}
	write(1, "\n", 1);
}

int	is_queen_able(int *result, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (*(result + i) == *(result + idx))
			return (0);
		i++;
	}
	i = 0;
	while (i < idx)
	{
		if (*(result + idx) == *(result + i) - idx + i)
			return (0);
		if (*(result + idx) == *(result + i) + idx - i)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *result, int *cnt, int idx)
{
	if (idx == 10)
	{
		(*cnt)++;
		print_data(result);
		return ;
	}
	*(result + idx) = 0;
	while (*(result + idx) < 10)
	{
		if (is_queen_able(result, idx))
			solve(result, cnt, idx + 1);
		(*(result + idx))++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	result[10];
	int	cnt;

	cnt = 0;
	solve(result, &cnt, 0);
	return (cnt);
}
