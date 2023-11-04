/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:20:02 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/04 14:20:03 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(int game)
{
	if (game == CLEAR)
		ft_printf("GAME CLEAR\n");
	else if (game == OVER)
		ft_printf("GAME OVER\n");
	exit(EXIT_SUCCESS);
}

void	play_game(t_map *m)
{
	m->mlx = mlx_init();
	if (!m->mlx)
		exit(EXIT_FAILURE);
	m->win = mlx_new_window(m->mlx, \
		m->width * 32, m->height * 32 + 25, "so_long");
	if (!m->win)
		exit(EXIT_FAILURE);
	m->player_lr = RIGHT;
	init_image(m);
	display_image(m);
	mlx_key_hook(m->win, key_hook, m);
	mlx_hook(m->win, KEY_EXIT, 0, exit_game, OVER);
	mlx_loop(m->mlx);
}
