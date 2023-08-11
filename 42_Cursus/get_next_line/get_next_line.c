/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 06:00:23 by yonyoo            #+#    #+#             */
/*   Updated: 2023/08/12 03:23:25 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strjoin(char *a, char *b)
{
	char	*result;

	return (result);
}

char	**split(char *line)
{
	char	**result;

	return (result);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	char		*line;
	static char	*backup;

	read(fd, buf, BUFFER_SIZE);

	return (line);
}
