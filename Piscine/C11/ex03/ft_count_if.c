/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:34:16 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/25 15:52:48 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	cnt;
	int	idx;

	cnt = 0;
	idx = 0;
	while (idx < length)
	{
		if (f(*(tab + idx)))
			cnt++;
		idx++;
	}
	return (cnt);
}
