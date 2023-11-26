/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:26:09 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/26 18:40:10 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	int		size;
	t_stk	stk_a;
	t_stk	stk_b;

	stk_a.size = 0;
	stk_b.size = 0;
	if (argc < 2)
		exit_err();
	size = parse_input(argc, argv, &stk_a);
	if (size == 1)
		exit(0);
	exit(0);
}
