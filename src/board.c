/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:18:41 by sangylee          #+#    #+#             */
/*   Updated: 2023/02/01 16:45:10 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void	init_map(char **map_char, int **map_cnt, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		*(map_char + i) = (char *)malloc(sizeof(char) * col);
		*(map_cnt + i) = (int *)malloc(sizeof(int) * col);
		j = 0;
		while (j < col)
		{
			*(*(map_char + i) + j) = '.';
			*(*(map_cnt + i) + j) = 0;
			j++;
		}
		i++;
	}
}

int	init_map_char(char *file_name, char **map_char, int col, int size_data)
{
	char	*file_buf;
	int		i;
	int		file_read;

	file_buf = (char *)malloc(sizeof(char) * (col));
	file_read = open(file_name, O_RDONLY);
	read(file_read, file_buf, size_data + 1);
	i = 1;
	while (0 < read(file_read, file_buf, col - 1))
	{
		ft_strncpy(*(map_char + i), file_buf, col - 2);
		i++;
	}
	return (i - 1);
}

int	init_map_cnt(char **map_char, int **map_cnt, char *map_info, t_point pt)
{
	int	i;
	int	j;

	i = 0;
	while (i < pt.x)
	{
		j = 0;
		while (j < pt.y)
		{
			if (map_char[i][j] == map_info[0] || map_char[i][j] == '.')
				map_cnt[i][j] = 0;
			else if (map_char[i][j] == map_info[1])
				map_cnt[i][j] = -1;
			else
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
