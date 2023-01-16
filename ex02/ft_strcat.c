/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:54:54 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/15 20:06:14 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	idx;
	int	size;

	idx = 0;
	size = 0;
	while (*(dest + size))
	{
		size++;
	}
	while (*(src + idx))
	{
		*(dest + size + idx) = *(src + idx);
		idx++;
	}
	*(dest + size + idx) = '\0';
	return (dest);
}
