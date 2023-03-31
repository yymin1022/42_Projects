/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:52:58 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/23 14:58:35 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	idx;
	size_t	len;

	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	idx = 0;
	while (*(s + idx))
	{
		*(res + idx) = f(idx, *(s + idx));
		idx++;
	}
	*(res + idx) = '\0';
	return (res);
}
