/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:54:14 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 14:00:16 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);

void	init_board_side(int **board, char *arg)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < 4)
			board[0][i + 1] = arg[i * 2] - '0';
		else if (i < 8)
			board[5][i - 3] = arg[i * 2] - '0';
		else if (i < 12)
			board[i - 7][0] = arg[i * 2] - '0';
		else
			board[i - 11][5] = arg[i * 2] - '0';
		i++;
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
			ft_putchar(board[i][j] + '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
