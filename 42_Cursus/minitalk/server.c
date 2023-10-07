/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:49:43 by yonyoo            #+#    #+#             */
/*   Updated: 2023/10/08 02:21:16 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	ft_sighandler(int signal)
{
	static char	data;
	static int	bit;

	if (signal == SIGUSR1)
		data = 0;
	else if (signal == SIGUSR2)
		data = 1;
	if (bit < 7)
		data <<= 1;
	bit++;
	if (bit == 8)
	{
		// print data
		bit = 0;
		data = 0;
	}
}

static void	ft_print_pid(pid_t pid)
{
	// print pid
}

int	main(int argc, char** argv)
{
	ft_print_pid(getpid());
	signal(SIGUSR1, ft_sighandler);
	signal(SIGUSR2, ft_sighandler);
	while (1)
		pause();
	return (0);
}
