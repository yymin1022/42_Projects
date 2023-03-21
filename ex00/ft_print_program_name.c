/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:13:39 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/18 22:02:34 by yonyoo           ###   ########.fr       */
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
	char	*name;

	name = argv[argc - argc];
	ft_putchar(name);
}
