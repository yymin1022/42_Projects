/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 06:32:34 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/24 06:32:47 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*free_table(t_table *table)
{
	int	i;

	if (!table)
		return (NULL);
	free_mutex(table);
	if (table->fork_lock != NULL)
		free(table->fork_lock);
	if (table->philo)
	{
		i = 0;
		while (i < table->nbr_philo)
		{
			free(table->philo[i]);
			i++;
		}
		free(table->philo);
	}
	free(table);
	return (NULL);
}

static void	free_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_mutex_destroy(&table->philo[i]->general_meal_lock);
		pthread_mutex_destroy(&table->fork_lock[i]);
		i++;
	}
	pthread_mutex_destroy(&table->dinner_end_lock);
	pthread_mutex_destroy(&table->log_lock);
}
