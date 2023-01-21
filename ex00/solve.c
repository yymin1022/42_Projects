/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:03:19 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 16:18:02 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

int	solve(int **board, int idx)
{
	int	i;
	int	j;
	int	tmp;

	if (idx == 16)
	{
		if (check_board(board))
			return (1);
	}
	i = idx / 4 + 1;
	j = idx % 4 + 1;
	tmp = 1;
	while (tmp <= 4)
	{
		board[i][j] = tmp;
		if (check_col_dup(board, j) && check_row_dup(board, i))
		{
			if (solve(board, idx + 1))
				return (1);
		}
		tmp++;
	}
	return (0);
}
