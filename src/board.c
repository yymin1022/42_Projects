/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:18:41 by sangylee          #+#    #+#             */
/*   Updated: 2023/02/01 10:11:30 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq_header.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	idx;

	*(dest) = '.';
	idx = 1;
	while (*(src + idx - 1) && idx < n + 1)
	{
		*(dest + idx) = *(src + idx - 1);
		idx++;
	}
	*(dest + idx) = '.';
	*(dest + idx + 1) = '\0';
	return (dest);
}

void	init_arr(char **map_char, int **map_cnt, int row, int col)
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

void	init_board(char *file_name, char **map_char, int col, int size_data)
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
}

int	init_cnt(char **map_char, int **map_cnt, char *file_info, t_point pt)
{
	int	i;
	int	j;

	i = 0;
	while (i < pt.x)
	{
		j = 0;
		while (j < pt.y)
		{
			if (map_char[i][j] == file_info[0] || map_char[i][j] == '.')
				map_cnt[i][j] = 0;
			else if (map_char[i][j] == file_info[1])
				map_cnt[i][j] = -1;
			else
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
