/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:31:40 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/20 22:43:22 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_remove(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
	{
		if (c == *(set + i))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	from;
	size_t	to;
	size_t	i;

	if (!ft_strlen(s1))
		return (ft_strdup(s1));
	i = 0;
	while (*(s1 + i) && is_remove(*(s1 + i), set))
		i++;
	from = i;
	i = ft_strlen(s1) - 1;
	while (i > from && is_remove(*(s1 + i), set))
		i--;
	to = i;
	return (ft_substr(s1, from, to - from + 1));
}
