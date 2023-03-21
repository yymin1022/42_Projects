/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:52:54 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/28 17:35:24 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	while (*(tab + i) != 0)
	{
		j = 0;
		while (*(tab + j + 1) != 0)
		{
			if (cmp(*(tab + j), *(tab + j + 1)) > 0)
				swap (tab + j, tab + j + 1);
			j++;
		}
		i++;
	}
}
