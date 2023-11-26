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

static void	run_cmd(t_stk *stk_a, t_stk *stk_b, char *cmd)
{
	int	is_valid;

	is_valid = is_cmd_valid(stk_a, stk_b, cmd);
	if (is_valid < 0)
		exit_err();
	free(cmd);
}

static int	is_sort(t_stk *stk, int size)
{
	int		prev;
	t_list	*tmp;

	if (stk->size != size)
		return (0);
	prev = stk->top->num;
	tmp = stk->top->next;
	while (tmp)
	{
		if (prev > tmp->num)
			return (0);
		prev = tmp->num;
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		size;
	char	*cmd;
	t_stk	stk_a;
	t_stk	stk_b;

	stk_a.size = 0;
	stk_b.size = 0;
	if (argc < 2)
		exit_err();
	size = parse_input(argc, argv, &stk_a);
	cmd = get_next_line(0);
	while (cmd && cmd[0] != '\n')
	{
		run_cmd(&stk_a, &stk_b, cmd);
		cmd = get_next_line(0);
	}
	if (is_sort(&stk_a, size))
	{
		if (ft_printf("OK\n") != 3)
			exit_err();
	}
	else
		if (ft_printf("KO\n") != 3)
			exit_err();
	exit(0);
}
