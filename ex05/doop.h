/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:13:48 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/26 18:16:43 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H
# include <unistd.h>

int			ft_strlen(char *str);
int			get_op(char *str);
long long	calc_num(long long num1, long long num2, int op);
long long	get_num(char *str);
void		ft_putnbr(long long num);
void		ft_putstr(char *str);
void		ft_strrev(char *str);

#endif
