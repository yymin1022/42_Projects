/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:35:37 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/04 15:35:00 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_err(char *str)
{
	ft_printf("Error\n%s\n", str);
	exit(1);
}

void	check_valid_file(int argc, char **argv)
{
	char	*filename;
	size_t	len;

	if (argc != 2)
		exit_err("Invalid Args");
	filename = argv[1];
	len = ft_strlen(filename);
	if (len <= 4 || ft_strncmp(filename + len - 4, ".ber", 4) \
		|| filename[len - 5] == '/')
		exit_err("Invalid File");
}

static void	dfs_path(t_map *m, int x, int y)
{
	if (m->map[y][x] == '1' || m->is_visit[y][x])
		return ;
	m->is_visit[y][x] = 1;
	if (m->map[y][x] == 'E')
	{
		m->e_flag = 1;
		return ;
	}
	else if (m->map[y][x] == 'C')
		m->c_cnt++;
	dfs_path(m, x + 1, y);
	dfs_path(m, x - 1, y);
	dfs_path(m, x, y + 1);
	dfs_path(m, x, y - 1);
}

void	check_valid_path(t_map *m)
{
	init_is_visit(m);
	dfs_path(m, m->p_x, m->p_y);
	if (m->e_flag == 0 || m->c_cnt != m->c)
		exit_err("Map Error: No Valid Path");
	m->c_cnt = 0;
}
