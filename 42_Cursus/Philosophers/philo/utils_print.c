/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:26:59 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/30 14:27:28 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	print_error(void)
{
	printf("Error\n");
	return (1);
}

int	print_message(t_philo *philo, char *str)
{
	long long		now;

	if (philo->arg->dead == 1 || philo->arg->error == 1)
		return (1);
	get_cur_time(&now);
	printf("%lld %d %s\n", now - philo->arg->start_time, philo->philo_id, str);
	return (0);
}
