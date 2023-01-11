/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:46:11 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/11 15:54:37 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	alpha;
	int		idx;

	idx = 0;
	while (idx < 26)
	{
		alpha = idx + 'a';
		write(1, &alpha, 1);
		idx++;
	}
}
