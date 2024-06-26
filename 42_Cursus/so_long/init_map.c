/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:19:25 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/04 21:19:52 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(char *filename, t_map *m)
{
	int		fd;
	int		i;
	char	*line;
	size_t	len;

	m->map = (char **)malloc(sizeof(char *) * (m->height + 1));
	fd = open(filename, O_RDONLY);
	if (!m->map || fd < 0)
		exit_err("Memory Error");
	i = 0;
	while (i < m->height)
	{
		line = get_next_line(fd);
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		m->map[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!m->map[i])
			exit_err("Memory Error");
		ft_strlcpy(m->map[i++], line, len + 1);
		free(line);
	}
	m->map[i] = NULL;
	if (close(fd) < 0)
		exit_err("File Error");
}

void	init_map_info(char *filename, t_map *m)
{
	int		fd;
	char	*line;
	size_t	len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_err("File Error");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!m->width)
		{
			len = ft_strlen(line);
			if (line[len - 1] == '\n')
				m->width = len - 1;
			else
				m->width = len;
		}
		m->height++;
		free(line);
	}
	if (close(fd) < 0)
		exit_err("File Error");
}

void	init_is_visit(t_map *m)
{
	int	i;

	m->is_visit = (int **)malloc(sizeof(int *) * m->height);
	if (!m->is_visit)
		exit_err("Memory Error");
	i = 0;
	while (i < m->height)
	{
		m->is_visit[i] = (int *)ft_calloc(m->width, sizeof(int));
		if (!m->is_visit[i])
			exit_err("Memory Error");
		i++;
	}
}
