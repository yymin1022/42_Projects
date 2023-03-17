/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:46:49 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/17 13:57:19 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*(haystack + i) && i < len)
	{
		j = 0;
		while (*(needle + j))
		{
			if (*(haystack + i + j) != *(needle + j))
				break ;
			j++;
		}
		if (*(needle + j) == 0)
			return (haystack + i);
		i++;
	}
	return (0);
}
