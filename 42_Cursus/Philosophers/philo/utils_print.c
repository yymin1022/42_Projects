/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 06:29:51 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/27 02:27:33 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static char	*parse_status(t_state status)
{
	if (status == S_EATING)
		return ("is eating");
	else if (status == S_LEFT_FORK || status == S_RIGHT_FORK)
		return ("has taken a fork");
	else if (status == S_SLEEPING)
		return ("is sleeping");
	else if (status == S_THINKING)
		return ("is thinking");
	else if (status == S_DEAD)
		return ("died");
	else
		return ("");
}

void	*print_error(char *str, t_table *table)
{
	if (table)
		free_table(table);
	printf("%s", str);
	return (NULL);
}

void	log_status(t_philo *philo, t_state status)
{
	if (has_dinner_finish(philo->table) == true)
		return ;
	pthread_mutex_lock(&philo->table->log_lock);
	printf("%i %ld %s\n", get_time_ms(philo->table->start_dining),
			philo->id + 1, parse_status(status));
	pthread_mutex_unlock(&philo->table->log_lock);
}
