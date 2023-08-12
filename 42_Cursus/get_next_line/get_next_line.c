/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 06:00:23 by yonyoo            #+#    #+#             */
/*   Updated: 2023/08/12 18:56:46 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_a_line(char *backup, size_t size)
{
	char	*line;
	size_t	idx;

	idx = 0;
	line = (char *)malloc((size + 1) * sizeof(char));
	while (idx < size)
	{
		*(line + idx) = *(backup + idx);
		idx++;
	}
	*(line + idx) = '\0';
	return (line);
}

char	*find_new_line(char *backup, char *line)
{
	size_t	idx;

	idx = 0;
	while (*(backup + idx))
	{
		if (*(backup + idx) == '\n')
		{
			line = get_a_line(backup, idx);
			if (!line)
				return (NULL);
			break ;
		}
		idx++;
	}
	return (backup);
}

ssize_t	read_buffer(int fd, char *buf)
{
	ssize_t	read_size;

	read_size = read(fd, buf, BUFFER_SIZE);
	if(read_size < 0)
		return (-1);
	buf[read_size] = '\0';
	return (read_size);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	char		*line;
	static char	*backup;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	line = NULL;
	while (!find_new_line(backup, line))
	{
		if(read_buffer(fd, buf) < 0)
			return (0);
		backup = ft_strjoin(backup, buf);
		if (!backup)
			return (0);
	}
	return (line);
}
