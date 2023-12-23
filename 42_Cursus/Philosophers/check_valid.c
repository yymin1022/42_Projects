/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 06:32:05 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/24 06:46:26 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static bool	is_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

static bool	is_valid_input(int argc, char **argv)
{
	int		i;
	long	value;

	value = 0;
	i = 1;
	while (i < argc)
	{
		if (is_only_digit(argv[i]) == false)
		{
			printf("Error: Invalid Parameter");
			return (false);
		}
		value = ft_ato_long(argv[i]);
		if (value < 0 || value > LONG_MAX)
		{
			printf("Error: Invalid Parameter");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	is_valid_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: Invalid Parameter");
		return (false);
	}
	if (is_valid_input(argc, argv) == false)
		return (false);
	return (true);
}

bool	is_param_valid(t_table *table)
{
	if (table->nbr_philo > 200)
	{
		printf("Error: Invalid Parameter");
		return (false);
	}
	if (table->time_to_die < 60 || table->time_to_eat < 60
		|| table->time_to_sleep < 60)
	{
		printf("Error: Time must be greater than 60");
		return (false);
	}
	return (true);
}
