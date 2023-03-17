/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:46:49 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/17 18:47:37 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (*(char *)(haystack + i) && i < len)
	{
		j = 0;
		while (*(char *)(needle + j) && i + j < len)
		{
			if (*(char *)(haystack + i + j) != *(needle + j))
				break ;
			j++;
		}
		if (*(needle + j) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
