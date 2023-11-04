/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:19:44 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/04 15:41:55 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_map *m)
{
	int	w;
	int	h;
	int	i;

	m->img_0 = mlx_xpm_file_to_image(m->mlx, "./res/stone.xpm", &w, &h);
	m->img_1 = mlx_xpm_file_to_image(m->mlx, "./res/brick.xpm", &w, &h);
	m->img_c = mlx_xpm_file_to_image(m->mlx, "./res/apple.xpm", &w, &h);
	m->img_e = mlx_xpm_file_to_image(m->mlx, "./res/goldapple.xpm", &w, &h);
	m->img_p[0][0] = mlx_xpm_file_to_image(m->mlx, "./res/p.xpm", &w, &h);
	m->img_p[1][0] = mlx_xpm_file_to_image(m->mlx, "./res/p_l0.xpm", &w, &h);
	m->img_p[1][1] = mlx_xpm_file_to_image(m->mlx, "./res/p_l1.xpm", &w, &h);
	m->img_p[2][0] = mlx_xpm_file_to_image(m->mlx, "./res/p_r0.xpm", &w, &h);
	m->img_p[2][1] = mlx_xpm_file_to_image(m->mlx, "./res/p_r1.xpm", &w, &h);
	if (!m->img_0 || !m->img_1
		||!m->img_e || !m->img_c || !m->img_p[0][0])
		exit_err("Image File Error");
	i = 0;
	while (i < 4)
		if (!m->img_p[1][i] || !m->img_p[2][i++])
			exit_err("Image File Error");
}

void	show_image(t_map *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m->height)
	{
		j = -1;
		while (++j < m->width)
		{
			mlx_put_image_to_window(m->mlx, m->win, \
				m->img_0, j * 32, i * 32);
			if (m->map[i][j] == '1')
				mlx_put_image_to_window(m->mlx, m->win, \
					m->img_1, j * 32, i * 32);
			else if (m->map[i][j] == 'P')
				mlx_put_image_to_window(m->mlx, m->win, \
					m->img_p[0][0], j * 32, i * 32);
			else if (m->map[i][j] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, \
					m->img_e, j * 32, i * 32);
			else if (m->map[i][j] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, \
					m->img_c, j * 32, i * 32);
		}
	}
}

static void	show_moves(t_map *m)
{
	char	*moves;
	char	*movements;

	m->movement++;
	ft_printf("Moves: %d\n", m->movement);
	moves = ft_itoa(m->movement - 1);
	if (!moves)
		exit_err("Memory Error");
	movements = ft_strjoin("Movements: ", moves);
	if (!movements)
		exit_err("Memory Error");
	mlx_string_put(m->mlx, m->win, 10, m->height * 32 + 15, BLACK, movements);
	free(moves);
	free(movements);
	moves = ft_itoa(m->movement);
	if (!moves)
		exit_err("Memory Error");
	movements = ft_strjoin("Movements: ", moves);
	if (!movements)
		exit_err("Memory Error");
	mlx_string_put(m->mlx, m->win, 10, m->height * 32 + 15, WHITE, movements);
	free(moves);
	free(movements);
}

static void	move_player(t_map *m, int x, int y)
{
	if (m->map[y][x] == '1' || (m->map[y][x] == 'E' && m->c_cnt != m->c))
		return ;
	show_moves(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img_0, m->p_x * 32, m->p_y * 32);
	if (m->map[y][x] == 'E' && m->c_cnt == m->c)
	{
		mlx_put_image_to_window(m->mlx, m->win, \
			m->img_p[m->player_lr][m->movement % 2], x * 32, y * 32);
		mlx_destroy_window(m->mlx, m->win);
		finish_game(1);
	}
	else
	{
		mlx_put_image_to_window(m->mlx, m->win, m->img_0, x * 32, y * 32);
		mlx_put_image_to_window(m->mlx, m->win, \
			m->img_p[m->player_lr][m->movement % 2], x * 32, y * 32);
		m->p_x = x;
		m->p_y = y;
		if (m->map[y][x] == 'C')
		{
			m->map[y][x] = '0';
			m->c_cnt++;
		}
	}
}

int	key_hook(int keycode, t_map *m)
{
	if (keycode == KEY_LEFT)
	{
		m->player_lr = LEFT;
		move_player(m, m->p_x - 1, m->p_y);
	}
	else if (keycode == KEY_RIGHT)
	{
		m->player_lr = RIGHT;
		move_player(m, m->p_x + 1, m->p_y);
	}
	else if (keycode == KEY_DOWN)
		move_player(m, m->p_x, m->p_y + 1);
	else if (keycode == KEY_UP)
		move_player(m, m->p_x, m->p_y - 1);
	else if (keycode == KEY_ESC)
		finish_game(0);
	return (0);
}
