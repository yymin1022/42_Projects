/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:22:03 by sangylee          #+#    #+#             */
/*   Updated: 2023/02/01 20:02:43 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int	get_size(char *str)
{
	int		fd;
	int		len;
	char	c;

	len = 0;
	fd = open(str, O_RDONLY);
	while (0 < read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		len++;
	}
	close(fd);
	return (len);
}

int	get_col(char *str)
{
	int		fd;
	int		len;
	int		i;
	char	c;

	len = 0;
	i = 0;
	fd = open(str, O_RDONLY);
	while (0 < read(fd, &c, 1))
	{
		if (i == 1 && c != '\n')
			len++;
		if (c == '\n')
			i++;
		if (i == 2)
			break ;
	}
	close(fd);
	return (len);
}

char	*get_info(char *str)
{
	int		fd;
	char	*info;
	int		buffer;

	buffer = get_size(str);
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		info = (char *)malloc(1);
		info[0] = '\0';
		close(fd);
		return (info);
	}
	info = (char *)malloc(buffer);
	read(fd, info, buffer);
	close(fd);
	if ((info[buffer - 1] == info[buffer - 2])
		|| (info[buffer - 1] == info[buffer - 3])
		|| (info[buffer - 2] == info[buffer - 3]))
		info[0] = '\0';
	if (!check_printable(info[buffer - 1])
		|| !check_printable(info[buffer - 2])
		|| !check_printable(info[buffer - 3]))
		info[0] = '\0';
	return (info);
}

int	get_row(char *str, int len)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < len && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10;
		res += str[i] - '0';
		i++;
	}
	return (res);
}
