/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 06:32:05 by yonyoo            #+#    #+#             */
/*   Updated: 2023/12/27 02:43:05 by yonyoo           ###   ########seoul.kr  */
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

bool	is_valid_args(int argc, char **argv)
{
	int		i;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Invalid Parameter");
		return (false);
	}
	i = 1;
	while (i < argc)
	{
		if (is_only_digit(argv[i]) == false
			|| ft_atol(argv[i]) < 0 || ft_atol(argv[i]) > LONG_MAX)
		{
			printf("Error: Invalid Parameter");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	is_valid_args_value(t_table *table)
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
