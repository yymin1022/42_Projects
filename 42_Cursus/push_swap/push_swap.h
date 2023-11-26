/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:26:13 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/26 15:22:17 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

typedef struct s_cnt
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	total;
}	t_cnt;

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

int			push(char x, t_stk *stk_from, t_stk *stk_to);
int			rotate(char x, t_stk *stk);
int			rotate_r(t_stk *stk_a, t_stk *stk_b);
int			r_rotate(char x, t_stk *stk);
int			r_rotate_r(t_stk *stk_a, t_stk *stk_b);
int			swap(char x, t_stk *stk);
int			swap_s(t_stk *stk_a, t_stk *stk_b);
char		**ft_split(char const *str, char c);
int			calc_cnt_stk_a(t_stk *stk_a, long long val);
int			*find_pivot(t_list *stk, int size);
int			get_min_idx(int *arr, int size);
int			max(int a, int b);
int			min(int a, int b);
int			parse_input(int argc, char **argv, t_stk *stk);
long long	ft_atoll(const char *str);
void		algo(t_stk *stk_a, t_stk *stk_b);
void		exit_err();
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_sort_int_tab(int *tab, int size);
void		solve3(t_stk *stk);
void		sort_finish(t_stk *stk);
void		split_stk(t_stk *stk_a, t_stk *stk_b, int *pivot, int size);
t_cnt		calc_cnt(t_stk *stk_a, t_stk *stk_b, int idx, int tmp);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstlast_prev(t_list *lst);

#endif
