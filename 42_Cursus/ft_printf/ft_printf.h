/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:49:42 by yonyoo            #+#    #+#             */
/*   Updated: 2023/07/01 01:36:07 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int			ft_printf(const char *str, ...);
static void	print_format(va_list ap, const char format, int *cnt);
static void	print_char(char c, int *cnt);
static void	print_str(char *str, int *cnt);
static void	print_ptr(void *ptr, int *cnt);
static void	print_dec(int num, int *cnt);
static void	print_u_dec(unsigned int num, int *cnt);
static void	print_hex_lower(int num, int *cnt);
static void	print_hex_upper(int num, int *cnt);

#endif
