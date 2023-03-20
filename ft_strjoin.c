/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:21:38 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/20 21:27:16 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	size1;
	size_t	size2;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!res)
		return (0);
	i = 0;
	while (*(s1 + i))
	{
		*(res + i) = *(s1 + i);
		i++;
	}
	i = 0;
	while (*(s2 + i))
	{
		*(res + i + size1) = *(s2 + i);
		i++;
	}
	*(res + i + size1) = '\0';
	return (res);
}
