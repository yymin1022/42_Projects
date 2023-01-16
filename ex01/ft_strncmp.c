/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:44:46 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/16 18:37:12 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;

	if (!n)
		return (0);
	idx = 0;
	while (*(s1 + idx) && *(s2 + idx) && *(s1 + idx) == *(s2 + idx) && idx < n)
		idx++;
	return (*(s1 + idx - 1) - *(s2 + idx - 1));
}
