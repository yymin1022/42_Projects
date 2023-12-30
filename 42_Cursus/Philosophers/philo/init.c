/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:26:59 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/30 14:27:21 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_arg(t_arg *arg, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
	arg->philo_num = ft_atoll(argv[1]);
	arg->time_to_die = ft_atoll(argv[2]);
	arg->time_to_eat = ft_atoll(argv[3]);
	arg->time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
		arg->must_eat = ft_atoll(argv[5]);
	if (arg->philo_num < 1 || arg->time_to_die < 1 || arg->time_to_eat < 1
		|| arg->time_to_sleep < 1 || (argc == 6 && arg->must_eat < 1))
		return (1);
	arg->must_think = arg->time_to_eat - arg->time_to_sleep;
	return (0);
}

int	init_philo(t_philo **philo, t_arg *arg)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * (arg->philo_num + 1));
	if (!*philo)
		return (1);
	memset(*philo, 0, sizeof(t_philo) * (arg->philo_num + 1));
	while (++i <= arg->philo_num)
	{
		(*philo)[i].philo_id = i;
		(*philo)[i].arg = arg;
		(*philo)[i].right_fork = malloc(sizeof(pthread_mutex_t));
		if (!(*philo)[i].right_fork)
			return (free_philo(philo, i, 0));
		if (pthread_mutex_init((*philo)[i].right_fork, NULL) != 0)
			return (free_philo(philo, i, 2));
	}
	(*philo)[1].left_fork = (*philo)[arg->philo_num].right_fork;
	i = 1;
	while (++i <= arg->philo_num)
		(*philo)[i].left_fork = (*philo)[i - 1].right_fork;
	return (0);
}

int	init_thread(t_philo **philo, t_arg *arg)
{
	int	i;

	pthread_mutex_lock(arg->start_mutex);
	i = 0;
	while (++i <= arg->philo_num)
	{
		if (pthread_create(&(*philo)[i].thread_id, NULL,
			(void *)philo_routine_start, &(*philo)[i]) != 0)
		{
			pthread_mutex_unlock(arg->start_mutex);
			arg->error = 1;
			join_thread(philo, i);
			return (free_philo(philo, arg->philo_num + 1, 1));
		}
	}
	get_cur_time(&arg->start_time);
	pthread_mutex_unlock(arg->start_mutex);
	return (0);
}

int	init_monitor(t_philo **philo, t_arg *arg)
{
	int	i;
	int	state;

	while (1)
	{
		i = 0;
		while (++i <= arg->philo_num)
		{
			pthread_mutex_lock(arg->rsc_mutex);
			if ((*philo)[i].last_eat_time != 0)
			{
				state = check_state(philo, arg, i);
				if (state == 1)
					return (1);
				else if (state == 2)
					return (pthread_mutex_unlock(arg->rsc_mutex));
			}
			pthread_mutex_unlock(arg->rsc_mutex);
		}
		pthread_mutex_lock(arg->rsc_mutex);
		if (arg->done == arg->philo_num)
			return (pthread_mutex_unlock(arg->rsc_mutex));
		pthread_mutex_unlock(arg->rsc_mutex);
	}
}
