/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:19:09 by jongmoon          #+#    #+#             */
/*   Updated: 2023/01/29 15:20:54 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	convert(t_list *root, char *str, int len)
{
	int	period;

	if (len == 0)
	{
		return ;
	}
	else if (len == 1 && str[0] == '0')
	{
		print_value(root, 0, 0, NO_SPACE);
		return ;
	}
	period = (len - 1) % 3 + 1;
	convert_period(root, str, period);
	if (len > 3 && (str[0] != '0' || str[1] != '0' || str[2] != '0'))
	{
		print_value(root, 1, len - period, COMMA);
	}
	convert(root, str + period, len - period);
}

void	convert_period(t_list *root, char *str, int period)
{
	if (period == 1)
	{
		if (str[0] != '0')
		{
			print_value(root, str[0] - '0', 0, ONLY_SPACE);
		}
	}
	else if (period == 2)
	{
		convert_period_2(root, str);
	}
	else if (period == 3)
	{
		if (str[0] != '0')
		{
			print_value(root, str[0] - '0', 0, ONLY_SPACE);
			print_value(root, 1, 2, AND_LETTERS);
		}
		convert_period(root, str + 1, 2);
	}
}

void	convert_period_2(t_list *root, char *str)
{
	if (str[0] == '1')
	{
		if (str[1] == '0')
		{
			print_value(root, 1, 1, ONLY_SPACE);
		}
		else
		{
			print_value(root, 10 + (str[1] - '0'), 0, ONLY_SPACE);
		}
	}
	else
	{
		if (str[0] != '0')
		{
			print_value(root, str[0] - '0', 1, HYPHEN);
		}
		convert_period(root, str + 1, 1);
	}
}

void	print_value(t_list *root, int digit, int unit, t_print_option opt_new)
{
	static t_print_option	opt_old = NO_SPACE;
	char					*value;

	if (opt_old == ONLY_SPACE)
	{
		ft_putstr(" ");
	}
	else if (opt_old == HYPHEN)
	{
		ft_putstr("-");
	}
	else if (opt_old == COMMA)
	{
		ft_putstr(", ");
	}
	else if (opt_old == AND_LETTERS)
	{
		ft_putstr(" and ");
	}
	opt_old = opt_new;
	value = find_value(root, digit, unit);
	ft_putstr(value);
}

char	*find_value(t_list *root, int digit, int unit)
{
	t_list	*temp;

	temp = root->next;
	while (temp != NULL)
	{
		if (temp->data->digit == digit && temp->data->unit == unit)
		{
			return (temp->data->value);
		}
		temp = temp->next;
	}
	return (NULL);
}
