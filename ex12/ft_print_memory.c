/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:31:25 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/22 14:05:10 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_data_hex(unsigned char *addr)
{
	int	idx;

	idx = 0;
	while (idx < 16 && *(addr + idx))
	{
		if (idx % 2 == 0)
			write(1, " ", 1);
		write(1, &"0123456789ABCDEF"[*(addr + idx) / 16], 1);
		write(1, &"0123456789ABCDEF"[*(addr + idx) % 16], 1);
		idx++;
	}
	while (idx < 16)
	{
		write(1, "0", 1);
		if (idx % 2 == 0)
			break ;
		idx++;
	}
	while (idx <= 16)
	{
		write(1, " ", 1);
		idx++;
	}
}

void	ft_print_data_value(unsigned char *addr)
{
	int	idx;

	idx = 0;
	while (idx < 16)
	{
		if (*(addr + idx) >= 32 && *(addr + idx) <= 126)
			write(1, addr + idx, 1);
		else
			write(1, ".", 1);
		if (*(addr + idx) == '\0')
			break ;
		idx++;
	}
}

void	ft_print_mem_hex(unsigned long long addr)
{
	char	data[16];
	int		idx;
	int		tmp;

	idx = 0;
	while (addr >= 16)
	{
		data[idx] = "0123456789ABCDEF"[addr % 16];
		addr /= 16;
		idx++;
	}
	tmp = idx;
	while (tmp < 16)
	{
		write(1, "0", 1);
		tmp++;
	}
	data[idx] = "0123456789ABCDEF"[addr];
	while (*(data + idx))
	{
		write(1, data + idx, 1);
		idx--;
	}
	write(1, ":", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char		*data;
	unsigned int		mem_offset;

	mem_offset = 0;
	data = (unsigned char *)addr;
	while (mem_offset < size)
	{
		ft_print_mem_hex((unsigned long long)(addr + mem_offset));
		ft_print_data_hex(data + mem_offset);
		ft_print_data_value(data + mem_offset);
		write(1, "\n", 1);
		mem_offset += 16;
	}
	return (addr);
}
