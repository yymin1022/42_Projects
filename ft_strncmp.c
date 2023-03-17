/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:44:46 by yonyoo            #+#    #+#             */
/*   Updated: 2023/03/17 13:45:43 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (*(s1 + i) && *(s2 + i) && *(s1 + i) == *(s2 + i) && i < n - 1)
		i++;
	return (*(s1 + i) - *(s2 + i));
}
