/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:26:59 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/27 02:26:30 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static bool	start_dining(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		if (pthread_create(&table->philo[i]->thread_philo, NULL,
				&dining_routines, table->philo[i]) != 0)
			return (error_msg_null("Thread Creation Failed", table));
		i++;
	}
	if (table->nbr_philo > 1)
	{
		if (pthread_create(&table->thread_table, NULL, &finish_routines_reached,
				table) != 0)
			return (error_msg_null("Thread Creation Failed", table));
	}
	return (true);
}

static void	end_dining(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_join(table->philo[i]->thread_philo, NULL);
		i++;
	}
	if (table->nbr_philo > 1)
		pthread_join(table->thread_table, NULL);
	free_table(table);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (is_valid_args(argc, argv) == false)
		return (EXIT_FAILURE);
	table = init_table(argc, argv);
	if (!table)
		return (EXIT_FAILURE);
	if (start_dining(table) == false)
		return (EXIT_FAILURE);
	end_dining(table);
	return (EXIT_SUCCESS);
}
