/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:27:14 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/25 18:49:11 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (*(s1 + idx) && *(s2 + idx) && *(s1 + idx) == *(s2 + idx))
		idx++;
	return (*(s1 + idx) - *(s2 + idx));
}

void	swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (*(tab + i) != 0)
	{
		j = i + 1;
		while (*(tab + j) != 0)
		{
			if (ft_strcmp(*(tab + i), *(tab + j)) > 0)
				swap (tab + i, tab + j);
			j++;
		}
		i++;
	}
}
