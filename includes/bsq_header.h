/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:37:03 by sangylee          #+#    #+#             */
/*   Updated: 2023/01/30 09:54:15 by sangylee         ###   ########.fr       */
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
void	check_val(int (*t)[29], int i, int j, int *min_max);

//solve.c
int		find_max(int (*t)[29], int row, int col);
t_point	find_answer(int (*tab)[29], int row, int col);
void	draw_answer(char (*tab)[29], t_point pt, int max_value, char c);
int		print_answer(int (*tab)[29], char (*board)[29], t_point t, char c);
#endif
