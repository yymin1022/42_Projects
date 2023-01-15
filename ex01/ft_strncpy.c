/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:09:10 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/15 13:54:49 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (*(src + idx) && idx < n)
	{
		*(dest + idx) = *(src + idx);
		idx++;
	}
	while (idx < n)
	{
		*(dest + idx) = '\0';
		idx++;
	}
	return (dest);
}
