/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:49:45 by yonyoo            #+#    #+#             */
/*   Updated: 2023/10/08 17:14:44 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void ft_send_str(pid_t pid, size_t len, char *str)
{
	int		data;
	size_t	bit;
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		bit = 0;
		while (bit < 8)
		{
			data = (str[idx] >> (7 - bit)) & 1;
			if (data)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
		}
		idx++;
	}
}

static void	ft_parse_str(pid_t pid, char *str)
{
	char	*data;
	size_t	len;

	data = str; // str + '\n'
	if (!data)
		return;
	len = 0; //ft_strlen(data);
	ft_send_str(pid, len, data);
	free(data);
}

int	main(int argc, char** argv)
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
	ft_parse_str(pid, argv[2]);
	return (0);
}
