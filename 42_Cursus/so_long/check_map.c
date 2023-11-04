/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:35:21 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/04 14:18:53 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangular(t_map *m);
void	check_component(t_map *m);
void	check_pce(t_map *m);
void	check_surrounded(t_map *m);

void	check_valid_map(char *filename, t_map *m)
{
	init_map_info(filename, m);
	if (m->height > 32 || m->width > 54)
		error_exit("The map is too big.");
	init_map(filename, m);
	check_rectangular(m);
	check_component(m);
	check_pce(m);
	check_surrounded(m);
}

void	check_rectangular(t_map *m)
{
	int	i;

	i = 0;
	while (i < m->height)
	{
		if (ft_strlen(m->map[i]) != (size_t)m->width)
			error_exit("The map must be rectangular.");
		i++;
	}
}

void	check_component(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->height)
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'C')
				m->c++;
			else if (m->map[i][j] == 'E')
				m->e++;
			else if (m->map[i][j] == 'P')
			{
				m->p++;
				m->p_x = j;
				m->p_y = i;
			}
			else if (m->map[i][j] != '0' && m->map[i][j] != '1')
				error_exit("The map must be composed of (0, 1, C, E, P).");
			j++;
		}
		i++;
	}
}

void	check_pce(t_map *m)
{
	if (m->p != 1)
		error_exit("The map must contain 1 starting position.");
	else if (!m->c)
		error_exit("The map must contain at least 1 collectible.");
	else if (m->e != 1)
		error_exit("The map must contain 1 exit.");
}

void	check_surrounded(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->height)
	{
		if (i == 0 || i == m->height - 1)
		{
			j = 0;
			while (m->map[i][j])
			{
				if (m->map[i][j] != '1')
					error_exit("The map must be surrounded by walls.");
				j++;
			}
		}
		else if (m->map[i][0] != '1' || m->map[i][m->width - 1] != '1')
			error_exit("The map must be surrounded by walls.");
		i++;
	}
}
