/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:58:07 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/17 14:20:46 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	atoi(const char *str)
{
	size_t	i;
	int	neg_flag;
	int	res;

	i = 0;
	neg_flag = 1;
	if (*(str) == '-')
	{
		i++;
		neg_flag = -1;
	}
	res = 0;
	while (*(str + i))
	{
		if (*(str + i) < 48 || *(str + i) > 57)
			break ;
		res = res * 10 + *(str + i) - 48;
		i++;
	}
	return (res * neg_flag);
}
