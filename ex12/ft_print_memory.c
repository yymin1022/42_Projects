/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:31:25 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/14 21:36:23 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size)
{
	printf("%p\n%p\n%d", &addr, addr, size);
	return addr;
}

int main(){
	void* asdf = ft_print_memory;
	ft_print_memory(asdf, 10);
	return 0;
}
