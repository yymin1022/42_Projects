/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:10:31 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/18 13:02:29 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_heading(char *str, int *idx, int *sign)
{
	while (*(str + *idx))
	{
		if (*(str + *idx) == 32 || (*(str + *idx) >= 9 && *(str + *idx) <= 13))
			(*idx)++;
		else
			break ;
	}
	while (*(str + *idx))
	{
		if (*(str + *idx) == '+')
			(*idx)++;
		else if (*(str + *idx) == '-')
		{
			*sign = -(*sign);
			(*idx)++;
		}
		else
			break ;
	}
}

int	ft_atoi(char *str)
{
	int	ans;
	int	idx;
	int	sign;

	ans = 0;
	idx = 0;
	sign = 1;
	check_heading(str, &idx, &sign);
	while (*(str + idx))
	{
		if (*(str + idx) >= '0' && *(str + idx) <= '9')
		{
			ans *= 10;
			ans += *(str + idx) - '0';
		}
		else
			break ;
		idx++;
	}
	return (ans * sign);
}
