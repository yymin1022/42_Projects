/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:44:46 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/16 13:54:11 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (*(s1 + idx) && *(s2 + idx) && *(s1 + idx) == *(s2 + idx) && idx < n)
	{
		idx++;
	}
	return (*(s1 + idx) - *(s2 + idx));
}
