/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:13:48 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/26 21:24:13 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H
# include <unistd.h>

char	*ft_strrev(char *str);
int		ft_strlen(char *str);
int		get_op(char *str);
int		calc_num(int num1, int num2, int op);
int		get_num(char *str);
void	ft_putnbr(int num);
void	ft_putstr(char *str);

#endif
