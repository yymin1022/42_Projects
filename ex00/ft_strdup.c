/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:14:29 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/18 22:22:55 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*new_str;
	int		idx;
	int		src_size;

	src_size = 0;
	while (*(src + src_size))
		src_size++;
	new_str = (char *)malloc(src_size);
	idx = 0;
	while (idx < src_size)
	{
		*(new_str + idx) = *(src + idx);
		idx++;
	}
	return (new_str);
}
