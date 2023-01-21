/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:38:19 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 15:46:51 by yonyoo           ###   ########.fr       */
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

int	check_board(int **board)
{
	board[0][0] = 0;
	return (1);
}

int	check_col(int **board, int col)
{
	int	i;
	int	j;

	i = 1;
	while (i < 5)
	{
		if (board[i][col] == 0)
			return (1);
		j = i + 1;
		while (j < 5)
		{
			if (board[i][col] == board[j][col])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_row(int **board, int row)
{
	int	i;
	int	j;

	i = 1;
	while (i < 5)
	{
		if (board[row][i] == 0)
			return (1);
		j = i + 1;
		while (j < 5)
		{
			if (board[row][i] == board[row][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
