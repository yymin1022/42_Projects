/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:35:37 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/04 14:21:00 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	check_valid_file(int argc, char **argv)
{
	char	*filename;
	size_t	len;

	if (argc != 2)
		error_exit("Invalid argument");
	filename = argv[1];
	len = ft_strlen(filename);
	if (len <= 4 || ft_strncmp(filename + len - 4, ".ber", 4) \
		|| filename[len - 5] == '/')
		error_exit("Invalid filename");
}

void	valid_path(t_map *m, int x, int y)
{
	if (m->map[y][x] == '1' || m->visited[y][x])
		return ;
	m->visited[y][x] = TRUE;
	if (m->map[y][x] == 'E')
	{
		m->e_flag = TRUE;
		return ;
	}
	else if (m->map[y][x] == 'C')
		m->c_cnt++;
	valid_path(m, x + 1, y);
	valid_path(m, x - 1, y);
	valid_path(m, x, y + 1);
	valid_path(m, x, y - 1);
}

void	check_valid_path(t_map *m)
{
	init_visited(m);
	valid_path(m, m->p_x, m->p_y);
	if (m->e_flag == FALSE || m->c_cnt != m->c)
		error_exit("There is no valid path in the map.");
	m->c_cnt = 0;
}
