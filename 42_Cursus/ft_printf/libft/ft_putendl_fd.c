/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:17:22 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/23 15:23:33 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	idx;

	idx = 0;
	while (*(s + idx))
	{
		ft_putchar_fd(*(s + idx), fd);
		idx++;
	}
	ft_putchar_fd('\n', fd);
}
