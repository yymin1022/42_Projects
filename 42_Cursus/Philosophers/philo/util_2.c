/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:26:59 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/27 02:27:52 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	state_check(t_philo **philo, t_arg *arg, int i)
{
	long long		now;

	if (arg->error == 1)
	{
		pthread_mutex_unlock(arg->rsc_mutex);
		join_thread(philo, arg->philo_num + 1);
		free_philo(philo, arg->philo_num + 1, 1);
		return (1);
	}
	time_set(&now);
	if (now - (*philo)[i].last_eat_time > arg->time_to_die)
	{
		arg->dead = 1;
		printf("%lld %d died\n", now - arg->start_time, (*philo)[i].philo_id);
		return (2);
	}
	return (0);
}

int	print_message(t_philo *philo, char *str)
{
	long long		now;

	if (philo->arg->dead == 1 || philo->arg->error == 1)
		return (1);
	time_set(&now);
	printf("%lld %d %s\n", now - philo->arg->start_time, philo->philo_id, str);
	return (0);
}