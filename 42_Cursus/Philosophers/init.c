/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 06:28:06 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/24 06:48:14 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	sort_fork_by_philo(t_philo *philo)
{
	philo->fork[0] = philo->id;
	if (philo->table->nbr_philo > 1)
	{
		philo->fork[1] = (philo->id + 1) % philo->table->nbr_philo;
		if (philo->id % 2 != 0)
		{
			philo->fork[0] = (philo->id + 1) % philo->table->nbr_philo;
			philo->fork[1] = philo->id;
		}
	}
}

static pthread_mutex_t	*init_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	long			i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * table->nbr_philo);
	if (!forks)
		return (error_msg_null("Memory Allocation Error", NULL));
	while (i < table->nbr_philo)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (error_msg_null("Mutex Allocation Error", NULL));
		i++;
	}
	return (forks);
}

static bool	init_mutex(t_table *table)
{
	table->fork_lock = init_forks(table);
	if (!table->fork_lock)
		return (false);
	if (pthread_mutex_init(&table->dinner_end_lock, 0) != 0)
		return (error_msg_null("Mutex Allocation Error", NULL));
	if (pthread_mutex_init(&table->log_lock, 0) != 0)
		return (error_msg_null("Mutex Allocation Error", NULL));
	return (true);
}

static bool	init_philo(t_table *table)
{
	t_philo	**philos;
	long	i;

	i = 0;
	philos = malloc(sizeof(t_philo) * table->nbr_philo);
	if (philos == NULL)
		return (error_msg_null("Memory Allocation Error", NULL));
	while (i < table->nbr_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (philos[i] == NULL)
			return (error_msg_null("Memory Allocation Error", NULL));
		philos[i]->table = table;
		philos[i]->id = i;
		philos[i]->nbr_meals_done = 0;
		sort_fork_by_philo(philos[i]);
		if (pthread_mutex_init(&philos[i]->general_meal_lock, 0) != 0)
			return (error_msg_null("Mutex Allocation Error", NULL));
		i++;
	}
	table->philo = philos;
	return (true);
}

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (error_msg_null("Memory Allocation Error", NULL));
	table->nbr_philo = ft_ato_long(argv[1]);
	table->time_to_die = ft_ato_long(argv[2]);
	table->time_to_eat = ft_ato_long(argv[3]);
	table->time_to_sleep = ft_ato_long(argv[4]);
	table->time_must_eat = -1;
	if (argc == 6)
		table->time_must_eat = ft_ato_long(argv[5]);
	table->dinner_end = false;
	table->start_dining = datetime_now();
	if (init_philo(table) == false || table->philo == NULL)
		return (NULL);
	if (init_mutex(table) == false || is_param_valid(table) == false)
		return (NULL);
	return (table);
}
