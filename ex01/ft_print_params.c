/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:21:44 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/18 13:24:31 by yonyoo           ###   ########.fr       */
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

	idx = 1;
	while (idx < argc)
		ft_putchar(argv[idx++]);
}
