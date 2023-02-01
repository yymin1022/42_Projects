/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:07:26 by yonyoo            #+#    #+#             */
/*   Updated: 2023/02/01 11:22:04 by yonyoo           ###   ########.fr       */
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

void	free_memory(char **map_char, int **map_cnt, char *file_info)
{
	free(map_char);
	free(map_cnt);
	free(file_info);
}

void	print_err(int err)
{
	if (err == 1)
		write(2, "Map Error\n", 10);
	else if (err == 2)
		write(2, "Error\n", 6);
}
