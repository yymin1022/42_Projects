/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:03:19 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 15:30:16 by yonyoo           ###   ########.fr       */
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
		if(check_board(board))
			return (1);
		return (0);
	}
	i = idx / 4 + 1;
	j = idx % 4 + 1;
	tmp = 1;
	while (tmp <= 4)
	{
		board[i][j] = tmp;
		if (check_col(board, j) && check_row(board, i))
			solve(board, idx + 1);
		tmp++;
	}
	return (0);
}
