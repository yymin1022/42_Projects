/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:06:26 by jongmoon          #+#    #+#             */
/*   Updated: 2023/01/29 15:08:47 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	parse(char *file, t_list *root)
{
	int		i;
	int		digit;
	int		unit;
	char	*value;

	i = 0;
	while (file[i] != 0)
	{
		if (file[i] == '\n')
		{
			i++;
			continue ;
		}
		i += get_digit(file + i, &digit);
		i += get_unit(file + i, digit, &unit);
		i += get_value(file + i, &value);
		if (!push_back(root, digit, unit, value))
		{
			return (0);
		}
	}
	return (1);
}

int	get_digit(char *file, int *digit)
{
	int	i;

	i = 0;
	*digit = 0;
	while (file[i] != '0' && file[i] != ' ' && file[i] != ':')
	{
		*digit *= 10;
		*digit += file[i] - '0';
		i++;
	}
	return (i);
}

int	get_unit(char *file, int digit, int *unit)
{
	int	i;

	i = 0;
	*unit = 0;
	while (file[i] == '0')
	{
		if (digit != 0)
		{
			(*unit)++;
		}
		i++;
	}
	return (i);
}

int	get_value(char *file, char **value)
{
	int	i;
	int	len;
	int	start;

	i = 0;
	while (file[i] == ' ' || file[i] == ':')
	{
		i++;
	}
	start = i;
	len = 0;
	while (file[i] != '\n')
	{
		len++;
		i++;
	}
	*value = dup_len(file + start, len);
	return (i);
}

char	*dup_len(char *file, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		while (i < len)
		{
			str[i] = file[i];
			i++;
		}
		str[len] = 0;
	}
	return (str);
}
