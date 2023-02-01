/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:43:59 by sangylee          #+#    #+#             */
/*   Updated: 2023/02/01 12:17:52 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq_header.h"

int	get_result(char *file_name)
{
	t_point	cord;
	int		size_data;
	char	*map_info;
	char	**map_char;
	int		**map_cnt;

	map_info = get_info(file_name);
	size_data = get_size(file_name);
	cord.x = get_row(map_info, size_data - 3) + 2;
	cord.y = get_col(file_name) + 2;
	map_char = (char **)malloc(sizeof(char *) * cord.x);
	map_cnt = (int **)malloc(sizeof(int *) * cord.x);
	init_map(map_char, map_cnt, cord.x, cord.y);
	init_map_char(file_name, map_char, cord.y, size_data);
	if (!init_map_cnt(map_char, map_cnt, map_info + size_data - 3, cord))
	{
		free_memory(map_char, map_cnt, map_info, cord);
		return (-1);
	}
	if (!print_answer(map_cnt, map_char, cord, map_info[size_data - 1]))
	{
		free_memory(map_char, map_cnt, map_info, cord);
		return (-2);
	}
	return (0);
}

void	get_result_stdin(void)
{
	char	buf[15];
	char	c;
	int		fd;
	int		idx;
	int		row_cnt;

	fd = open("tmp_map", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	read(0, buf, 15);
	idx = 0;
	while (*(buf + idx) != '\n')
		idx++;
	write(fd, buf, idx);
	write(fd, "\n", 1);
	row_cnt = get_row(buf, idx - 3);
	idx = 0;
	while (idx < row_cnt)
	{
		read(0, &c, 1);
		write(fd, &c, 1);
		if (c == '\n')
			idx++;
	}
}

int	main(int argc, char **argv)
{
	int	idx;
	int	is_stdin;
	int	result;

	is_stdin = 0;
	if (argc < 2)
	{
		get_result_stdin();
		is_stdin = 1;
	}
	idx = 1;
	while (idx < argc || is_stdin)
	{
		if (is_stdin)
			result = get_result("tmp_map");
		else
			result = get_result(argv[idx++]);
		if (result == -1)
			print_err(1);
		else if (result == -2)
			print_err(2);
		if (is_stdin)
			break ;
		write(1, "\n", 1);
	}
	return (0);
}
