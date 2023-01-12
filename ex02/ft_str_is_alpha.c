/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:28:54 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/12 21:40:51 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		if (*(str + idx) >= 'A' && *(str + idx) <= 'Z')
			idx++;
		else if (*(str + idx) >= 'a' && *(str + idx) <= 'z')
			idx++;
		else
			return (0);
	}
	return (1);
}
