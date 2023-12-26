/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 06:34:12 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/27 02:35:59 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>

typedef enum e_fork
{
	F_LEFT = 0,
	F_RIGHT = 1
}	t_fork;

typedef enum e_state
{
	S_EATING,
	S_SLEEPING,
	S_THINKING,
	S_DEAD,
	S_LEFT_FORK,
	S_RIGHT_FORK,
	S_END_dining
}	t_state;

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				fork[2];
	long			id;
	long			nbr_meals_done;
	time_t			last_meal;
	t_table			*table;
	pthread_t		thread_philo;
	pthread_mutex_t	general_meal_lock;
}	t_philo;

typedef struct s_table
{
	bool			dinner_end;
	long			nbr_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_must_eat;
	time_t			start_dining;
	t_philo			**philo;
	pthread_t		thread_table;
	pthread_mutex_t	dinner_end_lock;
	pthread_mutex_t	*fork_lock;
	pthread_mutex_t	log_lock;
}	t_table;

bool	ft_isdigit(int c);
bool	has_dinner_finish(t_table *table);
bool	is_param_valid(t_table *table);
bool	is_valid_args(int argc, char **argv);
int		get_datetime(void);
long	ft_atol(const char *str);
long	handle_thinking_time(t_philo *philo);
void	*dining_routines(void *data);
void	*finish_routines_reached(void *data);
void	*free_table(t_table *table);
void	*print_error(char *str, t_table *table);
void	increment_times_eat_prop(t_philo *philo);
void	print_status(t_philo *philo, t_state status);
void	set_dinner_end_prop(t_table *table, bool value);
void	set_last_meal_prop(t_philo *philo, time_t value);
void	thread_sleep(t_table *table, time_t duration);
t_table	*init_table(int argc, char **argv);

#endif
