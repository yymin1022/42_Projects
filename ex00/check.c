/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:38:19 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 16:18:42 by yonyoo           ###   ########.fr       */
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

int	check_col_dup(int **board, int col)
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

int	check_row_dup(int **board, int row)
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
		idx++;
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
		idx++;
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
			return (0);
		if (!check_row_left(board, idx) || !check_row_right(board, idx))
			return (0);
	}
	return (1);
} 
