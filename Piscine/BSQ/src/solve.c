/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:28:59 by sangylee          #+#    #+#             */
/*   Updated: 2023/02/02 10:21:06 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int	find_max(int **t, int row, int col)
{
	int	max;
	int	i;
	int	j;

	max = 0;
	i = 1;
	while (i < row - 1)
	{
		j = 1;
		while (j < col - 1)
		{
			if (t[i][j] != -1)
				check_val(t, i, j, &max);
			j++;
		}
		i++;
	}
	return (max);
}

t_point	find_answer(int **tab, int row, int col)
{
	int		max_value;
	int		i;
	int		j;
	t_point	res;

	max_value = find_max(tab, row, col);
	i = 1;
	res.x = -1;
	res.y = -1;
	while (i < row - 1)
	{
		j = 1;
		while (j < col - 1)
		{
			if (tab[i][j] == max_value)
			{
				res.x = i;
				res.y = j;
				return (res);
			}
			j++;
		}
		i++;
	}
	return (res);
}

void	draw_answer(char **tab, t_point pt, int max_value, char c)
{
	int	i;
	int	j;

	i = pt.x - max_value + 1;
	while (i <= pt.x)
	{
		j = pt.y - max_value + 1;
		while (j <= pt.y)
		{
			tab[i][j] = c;
			j++;
		}
		i++;
	}
}

int	print_answer(int **tab, char **board, t_point t, char c)
{
	int		max_value;
	int		i;
	t_point	pt;

	max_value = find_max(tab, t.x, t.y);
	if (max_value == 0)
		return (0);
	pt = find_answer(tab, t.x, t.y);
	draw_answer(board, pt, max_value, c);
	i = 1;
	while (i < t.x - 1)
	{
		write(1, board[i] + 1, t.y - 2);
		write(1, "\n", 1);
		i++;
	}
	return (1);
}
