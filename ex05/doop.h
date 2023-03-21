/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:13:48 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/28 11:07:00 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H
# include <unistd.h>

char	*ft_strrev(char *str);
int		calc_num(int num1, int num2, int op);
int		calc_operator(int num1, int num2, int (*op)(int, int));
int		ft_strlen(char *str);
int		get_num(char *str);
int		get_op(char *str);
int		plus(int num1, int num2);
int		minus(int num1, int num2);
int		multiply(int num1, int num2);
int		division(int num1, int num2);
int		modulo(int num1, int num2);
void	ft_putnbr(long long num);
void	ft_putstr(char *str);

#endif
