/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:35:21 by yonyoo            #+#    #+#             */
/*   Updated: 2023/10/31 02:29:17 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_data(char *file, t_solong *data)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error("File Open Error");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (data->width == 0)
			data->width = ft_strlen(line) - 1;
		data->height++;
		free(line);
	}
	if (close(fd) < 0)
		exit_error("File Close Error");
}

static void	init_data_map(char *file, t_solong *data)
{
	int		fd;
	int		idx;
	char	*line;
	size_t	len;

	data->map = (char **)malloc(sizeof(char *) * (data->height + 1));
	fd = open(file, O_RDONLY);
	if (!(data->map) || fd < 0)
		exit_error("Map Read Error");
	idx = 0;
	while (idx < data->height)
	{
		line = get_next_line(fd);
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		data->map[idx] = (char *)malloc(sizeof(char) * (len + 1));
		if(!(data->map[idx]))
			exit_error("Memory Error");
		ft_strlcpy(data->map[idx], line, len + 1);
		free(line);
		idx++;
	}
}

static void	check_rect_surround(t_solong *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		if(i == 0 || i == data->height - 1)
		{
			j = 0;
			while (j < data->width)
			{
				if (data->map[i][j] != '1')
					exit_error("Map Error");
				j++;
			}
		}
		i++;
	}
}

void	check_map_valid(char *file, t_solong *data)
{
	init_data(file, data);
	init_data_map(file, data);
	check_rect_surround(data);
}
