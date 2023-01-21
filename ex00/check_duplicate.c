/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:43:21 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 18:43:49 by yonyoo           ###   ########.fr       */
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
