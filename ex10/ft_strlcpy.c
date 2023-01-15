/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:46:45 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/15 10:18:54 by yonyoo           ###   ########.fr       */
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
	idx--;
	*(dest + idx) = '\0';
	return (idx);
}
