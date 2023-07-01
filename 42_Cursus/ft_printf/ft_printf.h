/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:49:42 by yonyoo            #+#    #+#             */
/*   Updated: 2023/07/01 20:48:35 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
void	print_char(char c, int *cnt);
void	print_str(char *str, int *cnt);
void	print_ptr(void *ptr, int *cnt);
void	print_dec(int num, int *cnt);
void	print_u_dec(unsigned int num, int *cnt);
void	print_hex_lower(unsigned int num, int *cnt);
void	print_hex_upper(unsigned int num, int *cnt);

#endif
