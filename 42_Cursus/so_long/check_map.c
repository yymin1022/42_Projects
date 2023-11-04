/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:35:21 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/04 15:35:40 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_rectangular(t_map *m)
{
	int	i;

	i = 0;
	while (i < m->height)
	{
		if (ft_strlen(m->map[i]) != (size_t)m->width)
			exit_err("Map Error: No Rectangular Map");
		i++;
	}
}

static void	check_component(t_map *m)
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
				exit_err("Map Error: Unknown Map Item");
			j++;
		}
		i++;
	}
}

static void	check_pce(t_map *m)
{
	if (m->p != 1)
		exit_err("Map Error: No Start");
	else if (!m->c)
		exit_err("Map Error: No Collectible");
	else if (m->e != 1)
		exit_err("Map Error: No Exit");
}

static void	check_surrounded(t_map *m)
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
					exit_err("Map Error: Not Surrounded with Wall");
				j++;
			}
		}
		else if (m->map[i][0] != '1' || m->map[i][m->width - 1] != '1')
			exit_err("Map Error: Not Surrounded with Wall");
		i++;
	}
}

void	check_valid_map(char *filename, t_map *m)
{
	init_map_info(filename, m);
	init_map(filename, m);
	check_rectangular(m);
	check_component(m);
	check_pce(m);
	check_surrounded(m);
}
