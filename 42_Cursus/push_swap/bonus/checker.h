/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:26:13 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/26 18:40:41 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# include "get_next_line/get_next_line_bonus.h"

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_list;

typedef struct s_stk
{
	int				size;
	struct s_list	*top;
}	t_stk;

int			push(t_stk *stk_from, t_stk *stk_to);
int			rotate(t_stk *stk);
int			rotate_r(t_stk *stk_a, t_stk *stk_b);
int			r_rotate(t_stk *stk);
int			r_rotate_r(t_stk *stk_a, t_stk *stk_b);
int			swap(t_stk *stk);
int			swap_s(t_stk *stk_a, t_stk *stk_b);
char		**ft_split(char const *str, char c);
int			is_cmd_valid(t_stk *stk_a, t_stk *stk_b, char *cmd);
int			parse_input(int argc, char **argv, t_stk *stk);
long long	ft_atoll(const char *str);
void		arr_len(char **arr, int *size);
void		exit_err(void);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		split_stk(t_stk *stk_a, t_stk *stk_b, int *pivot, int size);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstlast_prev(t_list *lst);

#endif
