/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:37:03 by sangylee          #+#    #+#             */
/*   Updated: 2023/01/30 21:19:02 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_HEADER_H
# define BSQ_HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

//value_check.c 
int		check_min(int x, int y, int d);
void	check_val(int **t, int i, int j, int *min_max);

//solve.c
int		find_max(int **t, int row, int col);
t_point	find_answer(int **tab, int row, int col);
void	draw_answer(char **tab, t_point pt, int max_value, char c);
int		print_answer(int **tab, char **board, t_point t, char c);

//get.c
int		get_size(char *str);
int		get_col(char *str);
int		get_row(char *str, int len);
char	*get_info(char *str);

//board.c
char	*ft_strncpy(char *dest, char *src, int n);
int		init_cnt(char **map_char, int **map_cnt, char *file_info, t_point pt);
void	init_arr(char **map_char, int **map_cnt, int row, int col);
void	init_board(char *file_name, char **map_char, int col, int size_data);
#endif
