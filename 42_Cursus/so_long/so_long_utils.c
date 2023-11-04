/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:35:37 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/04 15:21:07 by yonyoo           ###   ########seoul.kr  */
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

void	valid_path(t_map *m, int x, int y)
{
	if (m->map[y][x] == '1' || m->is_visit[y][x])
		return ;
	m->is_visit[y][x] = TRUE;
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
	init_is_visit(m);
	valid_path(m, m->p_x, m->p_y);
	if (m->e_flag == FALSE || m->c_cnt != m->c)
		exit_err("Map Error: No Valid Path");
	m->c_cnt = 0;
}
