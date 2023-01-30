/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:43:59 by sangylee          #+#    #+#             */
/*   Updated: 2023/01/30 20:50:32 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq_header.h"

int	get_result(char *file_name)
{
	t_point	cord;
	int		size_data;
	char	*file_info;
	char	**map_char;
	int		**map_cnt;

	file_info = get_info(file_name);
	size_data = get_size(file_name);
	cord.x = get_row(file_info, size_data - 3) + 2;
	cord.y = get_col(file_name) + 2;
	map_char = (char **)malloc(sizeof(char *) * cord.x);
	map_cnt = (int **)malloc(sizeof(int *) * cord.x);
	init_arr(map_char, map_cnt, cord.x, cord.y);
	init_board(file_name, map_char, cord.y, size_data);
	init_cnt(map_char, map_cnt, file_info + size_data - 3, cord);
	if (!print_answer(map_cnt, map_char, cord, 'x'))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		idx;

	if (argc < 2)
	{
		printf("No Input\n");
		return (0);
	}
	idx = 1;
	while (idx < argc)
	{
		get_result(argv[idx]);
		idx++;
	}
}
