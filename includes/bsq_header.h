/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:37:03 by sangylee          #+#    #+#             */
/*   Updated: 2023/02/01 17:40:15 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_HEADER_H
# define BSQ_HEADER_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

int		check_min(int x, int y, int d);
int		check_printable(unsigned char c);
int		find_max(int **t, int row, int col);
int		get_col(char *str);
int		get_row(char *str, int len);
int		get_size(char *str);
int		init_map_char(char *file_name, char **map_char, int col, int size_data);
int		init_map_cnt(char **map_char, int **map_cnt, char *info, t_point pt);
int		print_answer(int **tab, char **board, t_point t, char c);
char	*ft_strncpy(char *dest, char *src, int n);
char	*get_info(char *str);
void	check_val(int **t, int i, int j, int *min_max);
void	draw_answer(char **tab, t_point pt, int max_value, char c);
void	free_memory(char **map_char, int **map_cnt, char *info, t_point pt);
void	init_map(char **map_char, int **map_cnt, int row, int col);
void	print_err(int err);
t_point	find_answer(int **tab, int row, int col);
#endif
