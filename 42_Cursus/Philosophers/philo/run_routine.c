/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 06:30:23 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/27 02:35:07 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	keep_sleeping(t_philo *philo)
{
	print_status(philo, S_SLEEPING);
	thread_sleep(philo->table, philo->table->time_to_sleep);
}

static void	keep_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_lock[philo->fork[F_LEFT]]);
	print_status(philo, S_LEFT_FORK);
	pthread_mutex_lock(&philo->table->fork_lock[philo->fork[F_RIGHT]]);
	print_status(philo, S_RIGHT_FORK);
	print_status(philo, S_EATING);
	set_last_meal_prop(philo, get_datetime());
	thread_sleep(philo->table, philo->table->time_to_eat);
	if (has_dinner_finish(philo->table) == false)
		increment_times_eat_prop(philo);
	pthread_mutex_unlock(&philo->table->fork_lock[philo->fork[F_RIGHT]]);
	pthread_mutex_unlock(&philo->table->fork_lock[philo->fork[F_LEFT]]);
}

static void	keep_thinking(t_philo *philo, bool log)
{
	time_t	time_thinking;

	time_thinking = handle_thinking_time(philo);
	if (log == true)
		print_status(philo, S_THINKING);
	thread_sleep(philo->table, time_thinking);
}

static void	*lonely_philo(t_philo *philo)
{
	print_status(philo, S_LEFT_FORK);
	thread_sleep(philo->table, philo->table->time_to_die);
	print_status(philo, S_DEAD);
	return (NULL);
}

void	*dining_routines(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->time_must_eat == 0)
		return (NULL);
	set_last_meal_prop(philo, philo->table->start_dining);
	if (philo->table->nbr_philo == 1)
		return (lonely_philo(philo));
	if (philo->id % 2 != 0)
		keep_thinking(philo, false);
	while (has_dinner_finish(philo->table) == false)
	{
		keep_eating(philo);
		keep_sleeping(philo);
		keep_thinking(philo, true);
	}
	return (NULL);
}
