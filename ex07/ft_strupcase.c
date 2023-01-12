/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:40:44 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/12 22:44:14 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		if (*(str + idx) >= 65 && *(str + idx) <= 90)
			*(str + idx) += 32;
		idx++;
	}
	return (str);
}

int main(){
	char *tmp1 = "Hello, World!";

	printf("%s", ft_strupcase(tmp1));
}
