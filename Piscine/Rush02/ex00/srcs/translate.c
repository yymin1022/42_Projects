/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:03:31 by jongmoon          #+#    #+#             */
/*   Updated: 2023/01/29 15:22:14 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	translate(char *dict_name, char *input)
{
	char	*file;
	t_list	*root;
	int		res;

	res = 2;
	file = read_dict(dict_name);
	if (file != NULL)
	{
		root = make_dict_list(file);
		if (root != NULL)
		{
			res = convert_raw(root, input);
			free_list(root);
		}
		free(file);
	}
	return (res);
}

int	translate_stdin(char *dict_name)
{
	int		n;
	char	buf[4096];
	int		res;

	res = 1;
	n = read(0, buf, 4096);
	if (n > 0)
	{
		buf[n - 1] = 0;
		res = translate(dict_name, buf);
	}
	return (res);
}

int	convert_raw(t_list *root, char *input)
{
	char	*trimmed;
	int		len;

	trimmed = trim_input(input);
	if (trimmed != NULL)
	{
		len = ft_strlen(trimmed);
		if (len == 0)
		{
			convert(root, "0", 1);
			ft_putstr("\n");
			return (0);
		}
		else if (len <= find_max_unit(root) + 3)
		{
			convert(root, trimmed, len);
			ft_putstr("\n");
			return (0);
		}
		return (2);
	}
	return (1);
}

char	*trim_input(char *input)
{
	int	i;

	i = 0;
	while ((input[i] >= '\t' && input[i] <= '\r') || input[i] == ' ')
	{
		i++;
	}
	if (input[i] == '+')
	{
		i++;
	}
	if (input[i] != 0 && ft_str_is_numeric(input + i))
	{
		while (input[i] == '0')
		{
			i++;
		}
		return (input + i);
	}
	return (NULL);
}

int	find_max_unit(t_list *root)
{
	int		max;
	t_list	*temp;

	max = 0;
	temp = root->next;
	while (temp != NULL)
	{
		if (temp->data->unit > max)
		{
			max = temp->data->unit;
		}
		temp = temp->next;
	}
	return (max);
}
