/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:22:57 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/14 12:43:27 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	idx;

	if (*str >= 97 && *str <= 122)
		*str -= 32;
	idx = 1;
	while (*(str + idx))
	{
		if (*(str + idx) >= 97 && *(str + idx) <= 122)
		{
			if (*(str + idx - 1) >= 9 && *(str + idx - 1) <= 13)
				*(str + idx) -= 32;
			else if (*(str + idx - 1) >= 32 && *(str + idx - 1) <= 47)
				*(str + idx) -= 32;
			else if (*(str + idx - 1) >= 57 && *(str + idx - 1) <= 64)
				*(str + idx) -= 32;
			else if (*(str + idx - 1) >= 91 && *(str + idx - 1) <= 96)
				*(str + idx) -= 32;
			else if (*(str + idx - 1) >= 123 && *(str + idx - 1) <= 126)
				*(str + idx) -= 32;
		}
		idx++;
	}
	return (str);
}
