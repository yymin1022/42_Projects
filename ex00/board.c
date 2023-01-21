/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:54:14 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 13:27:47 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_board_side(int **board, char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (i < 4)
			board[0][i] = arg[i];
		else if (i < 8)
			board[5][i - 4] = arg[i];
		else if (i < 16)
			board[i - 8][0] = arg[i];
		else
			board[i - 12][5] = arg[i];
	}
}

void	init_board(int **board,  char *arg)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	init_board_side(board, arg);
}

void	print_board(int **board)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			ft_putstr(board[i][j] - '0');
			j++;
		}
		i++;
	}
}
