/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:39:12 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/04 14:18:27 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx/mlx.h"

# define TRUE		1
# define FALSE		0
# define CLEAR		1
# define OVER		0
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_DOWN	125
# define KEY_UP		126
# define KEY_ESC	53
# define KEY_EXIT	17
# define LEFT		1
# define RIGHT		2
# define BLACK		0x00000000
# define WHITE		0x00FFFFFF

typedef struct s_map
{
	char	**map;
	int		**visited;
	int		width;
	int		height;
	int		p;
	int		c;
	int		e;
	int		p_x;
	int		p_y;
	int		e_flag;
	int		c_cnt;
	void	*mlx;
	void	*win;
	void	*img_0;
	void	*img_1;
	void	*img_p[3][4];
	int		player_lr;
	void	*img_e;
	void	*img_c;
	int		movement;
}	t_map;

void	check_valid_file(int argc, char **argv);
void	check_valid_map(char *filename, t_map *m);
void	check_valid_path(t_map *m);
void	error_exit(char *str);
void	init_map_info(char *filename, t_map *m);
void	init_map(char *filename, t_map *m);
void	init_visited(t_map *m);
void	play_game(t_map *m);
void	init_image(t_map *m);
void	display_image(t_map *m);
int		key_hook(int keycode, t_map *m);
int		exit_game(int game);

#endif
