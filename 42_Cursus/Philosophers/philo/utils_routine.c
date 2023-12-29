/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:26:59 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/27 02:27:52 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	philo_check_die(t_arg *arg, long long limit, long long time, int sleep_time)
{
	pthread_mutex_lock(arg->rsc_mutex);
	while ((!arg->dead && !arg->error) && time < limit)
	{
		pthread_mutex_unlock(arg->rsc_mutex);
		usleep(sleep_time * 2);
		get_cur_time(&time);
		pthread_mutex_lock(arg->rsc_mutex);
	}
	pthread_mutex_unlock(arg->rsc_mutex);
}

void	philo_routine_eat(t_philo *philo)
{
	long long		now;
	long long		limit;

	pthread_mutex_lock(philo->arg->rsc_mutex);
	get_cur_time(&now);
	if (print_message(philo, "is eating") == 0)
	{
		philo->last_eat_time = now;
		pthread_mutex_unlock(philo->arg->rsc_mutex);
		limit = now + philo->arg->time_to_eat;
		philo_check_die(philo->arg, limit, now, philo->arg->philo_num);
		philo->eat_count++;
	}
	else
		pthread_mutex_unlock(philo->arg->rsc_mutex);
}

void	philo_routine_sleep(t_philo *philo)
{
	long long		now;
	long long		limit;

	pthread_mutex_lock(philo->arg->rsc_mutex);
	get_cur_time(&now);
	if (print_message(philo, "is sleeping") == 0)
	{
		pthread_mutex_unlock(philo->arg->rsc_mutex);
		limit = now + philo->arg->time_to_sleep;
		philo_check_die(philo->arg, limit, now, philo->arg->time_to_sleep);
		pthread_mutex_lock(philo->arg->rsc_mutex);
		get_cur_time(&now);
		print_message(philo, "is thinking");
		pthread_mutex_unlock(philo->arg->rsc_mutex);
		if (philo->arg->must_think >= 0 && philo->arg->philo_num % 2 == 1)
		{
			limit = now + philo->arg->must_think;
			philo_check_die(philo->arg, limit, now, philo->arg->time_to_sleep);
			usleep(200);
		}
	}
	else
		pthread_mutex_unlock(philo->arg->rsc_mutex);
}

void	philo_fork_hold(t_philo *philo, int right)
{
	if (right == 1)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->arg->rsc_mutex);
	print_message(philo, "has taken a fork");
	pthread_mutex_unlock(philo->arg->rsc_mutex);
}

void	philo_fork_release(t_philo *philo, int right)
{
	if (right == 1)
		pthread_mutex_unlock(philo->right_fork);
	else
		pthread_mutex_unlock(philo->left_fork);
}