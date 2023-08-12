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

char	*get_a_line(char *backup, size_t size)
{
	char	*line;
	size_t	idx;

	idx = 0;
	line = (char *)malloc((size + 1) * sizeof(char));
	while (idx < size)
	{
		line[idx] = backup[idx];
		idx++;
	}
	line[idx] = '\0';
	return (line);
}

char	*next_backup(char *backup, size_t idx)
{
	char	*res;

	res = ft_strdup(backup + idx);
	if (!res)
		return (NULL);
	free(backup);
	return (res);
}

size_t	find_new_line(char **backup, char **line)
{
	size_t	idx;

	idx = 0;
	while ((*backup)[idx])
	{
		if ((*backup)[idx] == '\n')
		{
			*line = get_a_line(*backup, idx);
			if (!line)
				return (0);
			*backup = next_backup(*backup, idx + 1);
			return (1);
		}
		idx++;
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
		backup = (char *)malloc(sizeof(char));
	if (!backup)
		return (NULL);
	line = NULL;
	while (!find_new_line(&backup, &line))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			return (NULL);
		buf[read_size] = '\0';
		backup = ft_strjoin(backup, buf);
		if (!backup)
			return (NULL);
		if (read_size == 0)
			return (backup);
	}
	return (line);
}
