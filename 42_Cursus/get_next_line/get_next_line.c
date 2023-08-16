/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 06:00:23 by yonyoo            #+#    #+#             */
/*   Updated: 2023/08/12 19:45:26 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*get_a_line(char *backup, ssize_t size)
{
	char	*line;
	ssize_t	idx;

	if (!backup)
		return (NULL);
	line = (char *)malloc((size + 1) * sizeof(char));
	if (!line)
		return (NULL);
	idx = -1;
	while (++idx < size)
		line[idx] = backup[idx];
	line[idx] = '\0';
	return (line);
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
			*line = get_a_line(*backup, idx + 1);
			if (!(*line))
				return (0);
			*backup = next_backup(backup, idx + 1);
			return (1);
		}
	}
	return (0);
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
		if (read_size < 0)
			return (ft_free(&backup));
		if (ft_strlen(backup) == 0 && read_size == 0)
			return (ft_free(&backup));
		if (read_size == 0)
		{
			line = ft_strdup(backup);
			if (!line)
				return (ft_free(&backup));
			ft_free(&backup);
			return (line);
		}
		buf[read_size] = '\0';
		backup = ft_strjoin(backup, buf);
		if (!backup)
			return (NULL);
	}
	return (line);
}