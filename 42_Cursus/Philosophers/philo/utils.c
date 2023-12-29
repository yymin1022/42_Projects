/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:26:59 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/27 02:27:52 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_state(t_philo **philo, t_arg *arg, int i)
{
	long long		now;

	if (arg->error == 1)
	{
		pthread_mutex_unlock(arg->rsc_mutex);
		join_thread(philo, arg->philo_num + 1);
		free_philo(philo, arg->philo_num + 1, 1);
		return (1);
	}
	get_cur_time(&now);
	if (now - (*philo)[i].last_eat_time > arg->time_to_die)
	{
		arg->dead = 1;
		printf("%lld %d died\n", now - arg->start_time, (*philo)[i].philo_id);
		return (2);
	}
	return (0);
}

long long	get_cur_time(long long *rtn)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	*rtn = (time.tv_sec * 1000LL) + (time.tv_usec / 1000LL);
	return (*rtn);
}

void	join_thread(t_philo **philo, int i)
{
	while (--i > 0)
		pthread_join((*philo)[i].thread_id, NULL);
}

int	free_philo(t_philo **philo, int i, int flag)
{
	if (flag == 2)
		free((*philo)[i].right_fork);
	while (--i > 0)
	{
		if (flag >= 1)
			pthread_mutex_destroy((*philo)[i].right_fork);
		free((*philo)[i].right_fork);
	}
	free(*philo);
	return (1);
}

long long	ft_atoll(const char *str)
{
	int			i;
	long long	result;

	i = 0;
	result = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && i < 13)
			result = result * 10 + (str[i] - '0');
		else
			return (-1);
		i++;
	}
	if (result > 2147483647 || result < 0)
		return (-1);
	return (result);
}