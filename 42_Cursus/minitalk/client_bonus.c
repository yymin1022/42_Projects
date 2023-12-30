/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:49:45 by yonyoo            #+#    #+#             */
/*   Updated: 2023/10/08 19:35:57 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	check_callback(int sig)
{
	if (sig == SIGUSR1)
		ft_put_str("Server Got Message !\n");
	exit(0);
}

static void	ft_send_str(pid_t pid, size_t len, char *str)
{
	int		data;
	size_t	bit;
	size_t	idx;

	idx = 0;
	while (idx <= len)
	{
		bit = 0;
		while (bit < 8)
		{
			data = (str[idx] >> (7 - bit) & 1);
			if (data == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bit++;
		}
		idx++;
	}
}

static void	ft_parse_str(pid_t pid, char *str)
{
	char	*data;
	size_t	len;

	data = ft_strjoin(str, "\n");
	if (!data)
		return ;
	len = ft_strlen(data);
	ft_send_str(pid, len, data);
	free(data);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_put_str("Invalid Argument\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
	{
		ft_put_str("Invalid PID : ");
		ft_put_str(argv[1]);
		ft_put_str("\n");
		return (0);
	}
	signal(SIGUSR1, check_callback);
	ft_parse_str(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
