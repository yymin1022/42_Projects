/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:54:43 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/25 16:19:17 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	idx;

	idx = 1;
	while (idx < length - 1)
	{
		if (f(tab[idx - 1], tab[idx]) != 0 && f(tab[idx], tab[idx + 1]) != 0)
			if (f(tab[idx - 1], tab[idx]) != f(tab[idx], tab[idx + 1]))
				return (0);
		idx++;
	}
	return (1);
}
