/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:09:38 by yonyoo            #+#    #+#             */
/*   Updated: 2023/10/08 17:13:40 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str)
{
	int	idx;
	int	res;

	idx = 0;
	res = 0;
	while (str[idx])
	{
		if (str[idx] >= '0' && str[idx] <= '9')
			res = res * 10 + str[idx] - '0';
		else
			return (-1);
		if (res > 99998)
			return (-1);
		idx++;
	}
}

void	ft_put_str(char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
}
