/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:14:10 by jongmoon          #+#    #+#             */
/*   Updated: 2023/01/29 15:15:30 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	get_dict_size(char *dict)
{
	int		fd;
	int		size;
	char	buf[1];

	size = 0;
	fd = open(dict, O_RDONLY);
	if (fd < 0)
	{
		return (0);
	}
	while (read(fd, buf, 1) > 0)
	{
		size++;
	}
	close(fd);
	return (size);
}

char	*read_dict(char *dict)
{
	int		fd;
	int		size;
	char	*file;

	size = get_dict_size(dict);
	if (size == 0)
	{
		return (NULL);
	}
	fd = open(dict, O_RDONLY);
	if (fd < 0)
	{
		return (NULL);
	}
	file = (char *)malloc(sizeof(char) * (size + 1));
	if (file != NULL)
	{
		read(fd, file, size);
		file[size] = 0;
	}
	close(fd);
	return (file);
}

t_list	*make_dict_list(char *file)
{
	t_list	*root;

	root = (t_list *)malloc(sizeof(t_list));
	if (root != NULL)
	{
		root->next = NULL;
		if (parse(file, root))
		{
			return (root);
		}
		free_list(root);
	}
	return (NULL);
}
