/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:07:26 by yonyoo            #+#    #+#             */
/*   Updated: 2023/02/01 17:52:47 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	idx;

	dest[0] = '.';
	idx = 1;
	while (src[idx - 1] && idx < n + 1)
	{
		dest[idx] = src[idx - 1];
		idx++;
	}
	dest[idx] = '.';
	dest[idx + 1] = '\0';
	return (dest);
}

int	check_printable(unsigned char c)
{
	if (c >= 9 && c <= 13)
		return (1);
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	free_memory(char **map_char, int **map_cnt, char *map_info, t_point pt)
{
	int	i;

	i = 0;
	while (i < pt.x)
	{
		free(map_char[i]);
		free(map_cnt[i]);
		i++;
	}
	free(map_char);
	free(map_cnt);
	free(map_info);
}

void	print_err(int err)
{
	if (err == 1)
		write(2, "Map Error\n", 10);
	else if (err == 2)
		write(2, "Error\n", 6);
}
