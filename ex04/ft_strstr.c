/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:35:54 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/16 15:49:04 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	is_found;

	if (*to_find == '\0')
		return (str);
	i = 0;
	is_found = 0;
	while (*(str + i))
	{
		j = 0;
		while (*(to_find + j))
		{
			if (*(str + i + j) != *(to_find + j))
				break ;
			j++;
		}
		if (*(to_find + j) == '\0')
		{
			is_found = 1;
			break ;
		}
		i++;
	}
	if (!is_found)
		return (NULL);
	return (str + i);
}
