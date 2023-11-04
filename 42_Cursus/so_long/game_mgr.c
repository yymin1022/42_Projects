/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:20:02 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/04 15:45:16 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_map *m)
{
	m->mlx = mlx_init();
	if (!m->mlx)
		exit_err("MLX Error");
	m->win = mlx_new_window(m->mlx, \
		m->width * 32, m->height * 32 + 25, "so_long");
	if (!m->win)
		exit_err("MLX Error");
	m->player_dir = RIGHT;
	init_image(m);
	show_image(m);
	mlx_key_hook(m->win, key_hook, m);
	mlx_hook(m->win, KEY_EXIT, 0, finish_game, 0);
	mlx_loop(m->mlx);
}

int	finish_game(int game)
{
	if (game == 1)
		ft_printf("GAME CLEAR\n");
	else if (game == 0)
		ft_printf("GAME OVER\n");
	exit(EXIT_SUCCESS);
}
