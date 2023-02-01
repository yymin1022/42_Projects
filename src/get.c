/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:22:03 by sangylee          #+#    #+#             */
/*   Updated: 2023/01/31 22:02:25 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq_header.h"

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
	info = (char *)malloc(buffer);
	fd = open(str, O_RDONLY);
	read(fd, info, buffer);
	printf("ASDF %s\n", info);
	close(fd);
	return (info);
}

int	get_row(char *str, int len)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < len)
	{
		res = res * 10;
		res += str[i] - '0';
		i++;
	}
	return (res);
}
