/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:33:42 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/11 17:06:36 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_get_comb(char c[3])
{
	char	tmp[3];

	tmp = c;
	while (tmp[0] <= 7)
	{
		while (tmp[1] <= 8)
		{
			if (tmp[0] != tmp[1])
			{
				while (tmp[2] <= 9)
				{
					if (tmp[1] != tmp[2])
					{
						write (1, tmp, 1);
						write (1, tmp + 1, 1);
						write (1, tmp + 2, 1);
					}
					tmp[2]++;
				}
			}
			tmp[1]++;
		}
		tmp = c;
		tmp[0]++;
	}
}

void	ft_print_comb(void)
{
	char	c[3];

	c[0] = '0';
	c[1] = '1';
	c[2] = '2';
	ft_get_comb (c);
}

int main(){ft_print_comb();}
