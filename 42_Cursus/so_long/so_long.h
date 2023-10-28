/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:39:12 by yonyoo            #+#    #+#             */
/*   Updated: 2023/10/28 19:09:37 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "mlx/mlx.h"

typedef struct s_solong
{
	char	**map;
	int		**is_visit;
	int		height;
	int		width;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		c_cnt;
	int		*c_x;
	int		*c_y;
	int		move_cnt;
}	t_solong;

void	check_map_file(int argc, char **argv);
void	exit_error(char *str);
void	init_data(char *file, t_solong *data);
void	init_data_map(char *file, t_solong *data);

#endif
