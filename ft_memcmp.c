/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:41:45 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/17 13:45:59 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (*(s1 + i) && *(s2 + i) && i < n
			&& (unsigned char)*(s1 + i) == (unsigned char)*(s2 + i))
		i++;
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}
