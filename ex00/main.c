/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:26:33 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 13:48:08 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_arg(char *arg);
void	ft_putstr(char *str);
void	init_board(int **board, char *arg);
void	print_board(int **board);
void	print_err(int err);

int main(int argc, char **argv)
{
	int	**board;
	int	tmp;

	if (argc != 2)
	{
		print_err(0);
		return (0);
	}
	if (!check_arg(argv[1]))
	{
		print_err(0);
		return (0);
	}
	tmp = 0;
	board = (int **)malloc(sizeof(int *) * 6);
	while (tmp < 6)
	{
		board[tmp] = (int *)malloc(sizeof(int) * 6);
		tmp++;
	}
	init_board(board, argv[1]);
	print_board(board);
	return (0);
}
