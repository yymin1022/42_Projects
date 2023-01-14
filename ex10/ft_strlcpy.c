/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:46:45 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/14 19:06:17 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while ((*(src + idx)) && (*(dest + idx)) && idx < size)
	{
		*(dest + idx) = *(src + idx);
		idx++;
	}
	*(dest + idx - 1) = '\0';
	return (idx);
}
