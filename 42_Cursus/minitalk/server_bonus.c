/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:49:43 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/31 19:48:51 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	ft_sighandler(int signal, siginfo_t *info, void *f)
{
	static char	data;
	static int	bit;

	(void)f;
	if (signal == SIGUSR1)
		data |= 0;
	else if (signal == SIGUSR2)
		data |= 1;
	if (bit < 7)
		data <<= 1;
	bit++;
	if (bit == 8)
	{
		if (!data)
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &data, 1);
		bit = 0;
		data = 0;
	}
}

static void	ft_put_pid(pid_t pid)
{
	char	tmp;

	if (pid < 10)
	{
		tmp = pid + '0';
		write(1, &tmp, 1);
	}
	else
	{
		ft_put_pid(pid / 10);
		ft_put_pid(pid % 10);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	(void) argv;
	if (argc != 1)
	{
		write(1, "No Argument is Needed", 22);
		return (0);
	}
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &ft_sighandler;
	sigemptyset(&act.sa_mask);
	ft_put_pid(getpid());
	write(1, &"\n", 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
