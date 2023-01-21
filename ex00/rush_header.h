/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:25:47 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 14:29:10 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_HEADER_H
# define RUSH_HEADER_H
# include <stdlib.h>
# include <unistd.h>

int		check_arg(char *arg);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	init_board(int **board, char *arg);
void	init_board_side(int **board, char *arg);
void	print_board(int **board);
void	print_err(int err);

#endif
