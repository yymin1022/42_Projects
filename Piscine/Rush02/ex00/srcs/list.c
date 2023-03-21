/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:05:17 by jongmoon          #+#    #+#             */
/*   Updated: 2023/01/29 15:06:04 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_list	*create_elem(int digit, int unit, char *value)
{
	t_list	*list;

	if (value != NULL)
	{
		list = (t_list *)malloc(sizeof(t_list));
		if (list != NULL)
		{
			list->next = NULL;
			list->data = (t_entry *)malloc(sizeof(t_entry));
			if (list->data != NULL)
			{
				list->data->digit = digit;
				list->data->unit = unit;
				list->data->value = value;
				return (list);
			}
			free(list);
		}
		free(value);
	}
	return (NULL);
}

int	push_back(t_list *root, int digit, int unit, char *value)
{
	t_list	*temp;

	temp = root;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = create_elem(digit, unit, value);
	if (temp->next == NULL)
	{
		return (0);
	}
	return (1);
}

void	free_list(t_list *root)
{
	t_list	*temp;
	t_list	*next;

	temp = root->next;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp->data->value);
		free(temp->data);
		free(temp);
		temp = next;
	}
	free(root);
}
