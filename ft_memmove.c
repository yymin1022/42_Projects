/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:16:35 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/17 12:30:14 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t len)
{	
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (src < dest)
			*(dest + len - i - 1) = *(src + len - i - 1);
		else
			*(dest + i) = *(src + i);
		i++;
	}
