/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:38:19 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 18:42:33 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

int	check_col_dup(int **board, int idx, int val)
{
	int	i;

	i = 1;
	while (i < idx / 4 + 1)
	{
		if (board[i][idx % 4 + 1] == 0)
			return (1);
		if (board[i][idx % 4 + 1] == val)
			return (0);
		i++;
	}
	return (1);
}

int	check_row_dup(int **board, int idx, int val)
{
	int	i;

	i = 1;
	while (i < idx % 4 + 1)
	{
		if (board[idx / 4 + 1][i] == 0)
			return (1);
		if (board[idx / 4 + 1][i] == val)
			return (0);
		i++;
	}
	return (1);
}

int	check_col_up(int **board, int col)
{
	int	cnt;
	int	idx;
	int	max;

	cnt = 0;
	idx = 1;
	max = 0;
	while (idx < 5)
	{
		if (board[idx][col] > max)
		{
			cnt++;
			max = board[idx][col];
		}
		idx++;
	}
	if (cnt != board[0][col])
		return (0);
	return (1);
}

int	check_col_down(int **board, int col)
{
	int	cnt;
	int	idx;
	int	max;

	cnt = 0;
	idx = 4;
	max = 0;
	while (idx > 0)
	{
		if (board[idx][col] > max)
		{
			cnt++;
			max = board[idx][col];
		}
		idx--;
	}
	if (cnt != board[5][col])
		return (0);
	return (1);
}

int	check_row_left(int **board, int row)
{
	int	cnt;
	int	idx;
	int	max;

	cnt = 0;
	idx = 1;
	max = 0;
	while (idx < 5)
	{
		if (board[row][idx] > max)
		{
			cnt++;
			max = board[row][idx];
		}
		idx++;
	}
	if (cnt != board[row][0])
		return (0);
	return (1);
}

int	check_row_right(int **board, int row)
{
	int	cnt;
	int	idx;
	int	max;

	cnt = 0;
	idx = 4;
	max = 0;
	while (idx > 0)
	{
		if (board[row][idx] > max)
		{
			cnt++;
			max = board[row][idx];
		}
		idx--;
	}
	if (cnt != board[row][5])
		return (0);
	return (1);
}

int	check_board(int **board)
{
	int	idx;

	idx = 1;
	while (idx < 5)
	{
		if (!check_col_up(board, idx) || !check_col_down(board, idx))
		{
			return (0);
		}
		if (!check_row_left(board, idx) || !check_row_right(board, idx))
		{
			return (0);
		}
		idx++;
	}
	return (1);
}
