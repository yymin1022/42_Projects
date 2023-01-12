/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:40:16 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/12 19:27:18 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	char num[9];
	int idx;

	idx = 1;
	num[0] = '0';
	while (idx < n)
	{
		num[idx] = num[idx - 1] + 1;
	}
	
	while (num[0] <= 10 - n)
	{
		
	}
}

int main(){
	ft_print_combn(2);
}
