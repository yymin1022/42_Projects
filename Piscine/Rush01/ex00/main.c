/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:26:33 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/22 21:24:51 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

int	main(int argc, char **argv)
{
	int	**board;
	int	tmp;

	if (argc != 2 || !check_arg(argv[1]))
		return (ft_puterr(0));
	tmp = 0;
	board = (int **)malloc(sizeof(int *) * 6);
	if (board == 0)
		return (ft_puterr(2));
	while (tmp < 6)
	{
		board[tmp] = (int *)malloc(sizeof(int) * 6);
		if (board[tmp] == 0)
			return (ft_puterr(2));
		tmp++;
	}
	init_board(board, argv[1]);
	if (solve(board, 0))
		print_board(board);
	else
		return (ft_puterr(1));
	free(board);
	return (0);
}
