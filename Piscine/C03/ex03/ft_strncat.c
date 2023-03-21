/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:07:45 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/16 18:37:57 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idx;
	int				size;

	idx = 0;
	size = 0;
	while (*(dest + size))
		size++;
	while (*(src + idx) && idx < nb)
	{
		*(dest + size + idx) = *(src + idx);
		idx++;
	}
	*(dest + size + idx) = '\0';
	return (dest);
}
