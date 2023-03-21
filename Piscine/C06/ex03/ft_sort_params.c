/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:29:41 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/18 19:09:42 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *c)
{
	while (*c)
		write(1, c++, 1);
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (*(s1 + idx) && *(s2 + idx) && *(s1 + idx) == *(s2 + idx))
		idx++;
	return (*(s1 + idx) - *(s2 + idx));
}

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_sort_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(*(argv + i), *(argv + j)) > 0)
				ft_swap(argv + i, argv + j);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	idx;

	if (argc > 1)
	{
		ft_sort_params(argc, argv);
		idx = 1;
		while (idx < argc)
		{
			ft_putchar(*(argv + idx));
			idx++;
		}
	}
}
