/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:22:57 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/15 13:55:48 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	idx;

	if (*str >= 'a' && *str <= 'z')
		*str -= 32;
	idx = 1;
	while (*(str + idx))
	{
		if (*(str + idx) >= 'a' && *(str + idx) <= 'z')
		{
			if (*(str + idx - 1) < '0')
				*(str + idx) -= 32;
			else if (*(str + idx - 1) > '9' && *(str + idx - 1) < 'A')
				*(str + idx) -= 32;
			else if (*(str + idx - 1) > 'Z' && *(str + idx - 1) < 'a')
				*(str + idx) -= 32;
			else if (*(str + idx - 1) > 'z')
				*(str + idx) -= 32;
		}
		idx++;
	}
	return (str);
}
