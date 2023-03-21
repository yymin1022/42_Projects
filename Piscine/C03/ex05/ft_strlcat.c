/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:51:51 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/16 16:29:28 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	dest_size;
	unsigned int	src_size;

	dest_size = 0;
	while (*(dest + dest_size))
		dest_size++;
	src_size = 0;
	while (*(src + src_size))
		src_size++;
	if (size > 0)
	{
		idx = 0;
		while (*(src + idx) && dest_size + idx < size - 1)
		{
			*(dest + dest_size + idx) = *(src + idx);
			idx++;
		}
		*(dest + dest_size + idx) = '\0';
	}
	if (dest_size > size)
		return (src_size + size);
	return (dest_size + src_size);
}
