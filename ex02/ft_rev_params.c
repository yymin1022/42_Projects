/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:26:18 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/18 13:29:11 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *c)
{
	while (*c)
		write(1, c++, 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	idx;

	idx = argc - 1;
	while (idx > 0)
		ft_putchar(argv[idx--]);
}
