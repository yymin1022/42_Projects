/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 06:00:23 by yonyoo            #+#    #+#             */
/*   Updated: 2023/08/16 23:44:08 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_a_line(char **line, char *backup, ssize_t size)
{
	ssize_t	idx;

	if (!backup)
		return (NULL);
	*line = (char *)malloc((size + 1) * sizeof(char));
	if (!(*line))
		return (NULL);
	idx = -1;
	while (++idx < size)
		(*line)[idx] = backup[idx];
	(*line)[idx] = '\0';
	return (*line);
}

char	*next_backup(char **backup, ssize_t idx)
{
	char	*res;

	res = ft_strdup((*backup) + idx);
	if (!res)
		return (NULL);
	free(*backup);
	return (res);
}

size_t	find_new_line(char **backup, char **line)
{
	ssize_t	idx;

	idx = -1;
	while ((*backup)[++idx])
	{
		if ((*backup)[idx] == '\n')
		{
			if (!get_a_line(line, *backup, idx + 1))
				return (0);
			*backup = next_backup(backup, idx + 1);
			return (1);
		}
	}
	return (0);
}

char	*get_eof_line(char **line, char **backup)
{
	if (!get_a_line(&line, backup, ft_strlen(backup)))
		return (ft_free(&backup));
	ft_free(&backup);
	return (line);
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
		backup = ft_strdup("");
	if (!backup)
		return (NULL);
	line = NULL;
	while (!find_new_line(&backup, &line))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0 || (read_size == 0 && ft_strlen(backup) == 0))
			return (ft_free(&backup));
		if (read_size == 0)
			return (get_eof_line(&line, &backup));
		buf[read_size] = '\0';
		backup = ft_strjoin(backup, buf);
		if (!backup)
			return (NULL);
	}
	return (line);
}
