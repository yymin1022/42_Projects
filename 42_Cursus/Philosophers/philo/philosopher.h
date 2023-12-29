/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 06:34:12 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/27 02:39:56 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_arg
{
	long long		philo_num;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		must_eat;
	long long		start_time;
	long long		must_think;
	int				dead;
	int				error;
	int				done;
	pthread_mutex_t	*start_mutex;
	pthread_mutex_t	*rsc_mutex;
}				t_arg;

typedef struct s_philo
{
	pthread_t			thread_id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_arg				*arg;
	long long			last_eat_time;
	int					philo_id;
	int					eat_count;
}				t_philo;

long long	ft_atoll(const char *str);
long long	get_cur_time(long long *rtn);
int			init_arg(t_arg *arg, int argc, char **argv);
int			init_philo(t_philo **philo, t_arg *arg);
int			init_thread(t_philo **philo, t_arg *arg);
int			init_monitor(t_philo **philo, t_arg *arg);
void		join_thread(t_philo **philo, int i);
int			free_philo(t_philo **philo, int i, int flag);
int			print_error(void);
int			print_message(t_philo *philo, char *str);
int			check_state(t_philo **philo, t_arg *arg, int i);
void		philo_routine_eat(t_philo *philo);
void		philo_routine_sleep(t_philo *philo);
void		philo_routine_start(t_philo *philo);
void		philo_fork_hold(t_philo *philo, int right);
void		philo_fork_release(t_philo *philo, int right);

#endif
