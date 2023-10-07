/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:49:43 by yonyoo            #+#    #+#             */
/*   Updated: 2023/10/08 02:01:41 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	ft_sighandler(int signal)
{

}

static void	ft_print_pid(pid_t pid)
{
	// write pid
}

int	main(int argc, char** argv)
{
	pid_t	pid;

	if (argc != 1)
	{
		return (0);
	}
	pid = getpid();
	ft_print_pid(pid);
	signal(SIGUSR1, ft_sighandler);
	signal(SIGUSR2, ft_sighandler);
	while(1)
		pause();
	return (0);
}
