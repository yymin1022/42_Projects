/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:22:57 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/15 17:46:23 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_alpha_num(char str)
{
	if (str >= 'A' && str <= 'Z')
		return (1);
	else if (str >= 'a' && str <= 'z')
		return (2);
	else if (str >= '0' && str <= '9')
		return (3);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		if (is_alpha_num(*(str + idx)) == 1)
			*(str + idx) += 32;
		idx++;
	}
	if (is_alpha_num(*str) == 2)
		*str -= 32;
	idx = 1;
	while (*(str + idx))
	{
		if (is_alpha_num(*(str + idx)) == 2)
		{
			if (is_alpha_num(*(str + idx - 1)) == 0)
				*(str + idx) -= 32;
		}
		idx++;
	}
	return (str);
}
