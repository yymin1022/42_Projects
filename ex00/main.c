/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:26:33 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 12:53:59 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_arg(char *arg);
void	init_board(int **board, char *arg);
void	print_err(int err);

int main(int argc, char **argv)
{
	int	board[6][6];

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
	init_board(board, argv[1]);
	return (0);
}
