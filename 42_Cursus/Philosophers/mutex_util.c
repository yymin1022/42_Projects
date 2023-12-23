/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 06:29:27 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/24 06:29:33 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	set_last_meal_prop(t_philo *philo, time_t value)
{
	pthread_mutex_lock(&philo->general_meal_lock);
	philo->last_meal = value;
	pthread_mutex_unlock(&philo->general_meal_lock);
}

void	set_dinner_end_prop(t_table *table, bool value)
{
	pthread_mutex_lock(&table->dinner_end_lock);
	table->dinner_end = value;
	pthread_mutex_unlock(&table->dinner_end_lock);
}

void	increment_times_eat_prop(t_philo *philo)
{
	pthread_mutex_lock(&philo->general_meal_lock);
	philo->nbr_meals_done++;
	pthread_mutex_unlock(&philo->general_meal_lock);
}

bool	has_dinner_finish(t_table *table)
{
	bool	result;

	result = false;
	pthread_mutex_lock(&table->dinner_end_lock);
	if (table->dinner_end == true)
		result = true;
	pthread_mutex_unlock(&table->dinner_end_lock);
	return (result);
}
