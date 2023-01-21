/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:26:33 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 14:50:34 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

int	main(int argc, char **argv)
{
	int	**board;
	int	tmp;

	if (argc != 2)
	{
		ft_puterr(0);
		return (0);
	}
	if (!check_arg(argv[1]))
	{
		ft_puterr(0);
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
