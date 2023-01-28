/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:27:14 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/28 17:34:58 by yonyoo           ###   ########.fr       */
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
		j = 0;
		while (*(tab + j + 1) != 0)
		{
			if (ft_strcmp(*(tab + j), *(tab + j + 1)) > 0)
				swap (tab + j, tab + j + 1);
			j++;
		}
		i++;
	}
}
