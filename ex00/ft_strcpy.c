/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:39:29 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/12 21:08:23 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (*(src + idx))
	{
		*(dest + idx) = *(src + idx);
		idx++;
	}
	*(dest + idx) = '\0';

	return dest;
}
