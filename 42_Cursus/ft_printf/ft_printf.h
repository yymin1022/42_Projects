/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:49:42 by yonyoo            #+#    #+#             */
/*   Updated: 2023/07/17 18:07:53 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		print_char(char c, int *cnt);
int		print_str(char *str, int *cnt);
int		print_ptr(void *ptr, int *cnt);
int		print_dec(int num, int *cnt);
int		print_u_dec(unsigned int num, int *cnt);
int		print_hex_lower(unsigned int num, int *cnt);
int		print_hex_upper(unsigned int num, int *cnt);

#endif
