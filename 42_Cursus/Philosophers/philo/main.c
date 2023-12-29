/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:26:59 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/27 02:27:52 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	static pthread_mutex_t	start_mutex = PTHREAD_MUTEX_INITIALIZER;
	static pthread_mutex_t	rsc_mutex = PTHREAD_MUTEX_INITIALIZER;
	t_philo					*philo;
	t_arg					arg;

	memset(&arg, 0, sizeof(t_arg));
	arg.start_mutex = &start_mutex;
	arg.rsc_mutex = &rsc_mutex;
	if (init_arg(&arg, ac, av) == 1 || init_philo(&philo, &arg) == 1
		|| init_thread(&philo, &arg) == 1 || init_monitor(&philo, &arg) == 1)
		return (print_error());
	join_thread(&philo, arg.philo_num + 1);
	free_philo(&philo, arg.philo_num + 1, 1);
	return (0);
}