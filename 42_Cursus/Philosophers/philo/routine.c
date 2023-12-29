/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:26:59 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/27 02:27:52 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->arg->rsc_mutex);
	while (!philo->arg->dead && !philo->arg->error)
	{
		pthread_mutex_unlock(philo->arg->rsc_mutex);
		philo_fork_hold(philo, philo->philo_id % 2);
		philo_fork_hold(philo, (philo->philo_id + 1) % 2);
		philo_routine_eat(philo);
		philo_fork_release(philo, (philo->philo_id + 1) % 2);
		philo_fork_release(philo, philo->philo_id % 2);
		if (philo->arg->must_eat == philo->eat_count)
		{
			pthread_mutex_lock(philo->arg->rsc_mutex);
			philo->arg->done++;
			break ;
		}
		philo_routine_sleep(philo);
		pthread_mutex_lock(philo->arg->rsc_mutex);
	}
	pthread_mutex_unlock(philo->arg->rsc_mutex);
}

static int	philo_one(t_philo *philo)
{
	if (philo->arg->philo_num == 1)
	{
		pthread_mutex_lock(philo->arg->rsc_mutex);
		print_message(philo, "is thinking");
		pthread_mutex_unlock(philo->arg->rsc_mutex);
		philo_fork_hold(philo, 1);
		usleep(philo->arg->time_to_die * 1000);
		philo_fork_release(philo, 1);
		return (1);
	}
	return (0);
}

void	philo_routine_start(t_philo *philo)
{
	pthread_mutex_lock(philo->arg->start_mutex);
	pthread_mutex_lock(philo->arg->rsc_mutex);
	philo->last_eat_time = philo->arg->start_time;
	pthread_mutex_unlock(philo->arg->rsc_mutex);
	pthread_mutex_unlock(philo->arg->start_mutex);
	if (philo_one(philo) == 1)
		return ;
	if (philo->philo_id % 2 == 0
		|| (philo->philo_id % 2 == 1
			&& philo->philo_id == philo->arg->philo_num))
	{
		pthread_mutex_lock(philo->arg->rsc_mutex);
		print_message(philo, "is thinking");
		pthread_mutex_unlock(philo->arg->rsc_mutex);
		if (philo->arg->time_to_die > philo->arg->time_to_eat)
			usleep(philo->arg->time_to_eat * 500);
		else
			usleep(philo->arg->time_to_die * 1000);
	}
	philo_routine(philo);
}