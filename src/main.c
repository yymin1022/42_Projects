/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:43:59 by sangylee          #+#    #+#             */
/*   Updated: 2023/01/30 21:19:47 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq_header.h"

int	ft_print_err(int err)
{
	if (err == 1)
		write(2, "Map Error\n", 10);
	else if (err == 2)
		write(2, "No Answer\n", 10);
	return (-1);
}

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
	if (!init_cnt(map_char, map_cnt, file_info + size_data - 3, cord))
		return (-1);
	if (!print_answer(map_cnt, map_char, cord, 'x'))
		return (-2);
	return (0);
}

int	main(int argc, char **argv)
{
	int	idx;
	int	result;

	if (argc < 2)
	{
		printf("No Input\n");
		return (0);
	}
	idx = 1;
	while (idx < argc)
	{
		result = get_result(argv[idx]);
		if (result == -1)
			ft_print_err(1);
		else if (result == -2)
			ft_print_err(2);
		idx++;
	}
	return (0);
}
