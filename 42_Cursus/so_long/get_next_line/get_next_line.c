/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 06:00:23 by yonyoo            #+#    #+#             */
/*   Updated: 2023/10/28 16:16:09 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_a_line(char **line, char *backup, ssize_t size)
{
	ssize_t	idx;

	if (!backup)
		return (NULL);
	*line = (char *)malloc(size + 1);
	if (!(*line))
		return (NULL);
	idx = -1;
	while (++idx < size)
		(*line)[idx] = backup[idx];
	(*line)[idx] = '\0';
	return (*line);
}

static size_t	find_new_line(char **backup, char **line)
{
	char	*tmp;
	ssize_t	idx;

	idx = -1;
	while ((*backup)[++idx])
	{
		if ((*backup)[idx] == '\n')
		{
			if (!get_a_line(line, *backup, idx + 1))
				return (0);
			tmp = ft_strdup2((*backup) + idx + 1);
			ft_free2(backup);
			if (!tmp)
			{
				ft_free2(line);
				return (0);
			}
			*backup = tmp;
			return (1);
		}
	}
	return (0);
}

static char	*get_eof_line(char **line, char **backup)
{
	if (!get_a_line(line, *backup, ft_strlen2(*backup)))
		return (ft_free2(backup));
	ft_free2(backup);
	return (*line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*backup;
	ssize_t		read_size;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	if (!backup)
		backup = ft_strdup2("");
	if (!backup)
		return (NULL);
	line = NULL;
	while (!find_new_line(&backup, &line))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0 || (read_size == 0 && ft_strlen2(backup) == 0))
			return (ft_free2(&backup));
		if (read_size == 0)
			return (get_eof_line(&line, &backup));
		buf[read_size] = '\0';
		backup = ft_strjoin2(&backup, buf);
		if (!backup)
			return (NULL);
	}
	return (line);
}