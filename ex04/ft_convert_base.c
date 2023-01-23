/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:15:01 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/23 09:57:52 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_base(char *base);
int		ft_get_base(char cur, char *base);
void	ft_check_heading(char *str, int *idx, int *sign);
void	ft_rev_str(char *str);

long long	ft_atoi_base(char *str, char *base)
{
	int			idx;
	int			len_base;
	int			sign;
	int			tmp;
	long long	result;

	len_base = ft_check_base(base);
	idx = 0;
	sign = 1;
	ft_check_heading(str, &idx, &sign);
	result = 0;
	while (*(str + idx))
	{
		tmp = ft_get_base(*(str + idx), base);
		if (tmp == -1)
			break ;
		result *= len_base;
		result += tmp;
		idx++;
	}
	return (result * sign);
}

void	ft_putnbr(long long nbr, char *base, int base_len, char *result)
{
	int	idx;
	int	is_minus;

	idx = 0;
	is_minus = 0;
	if (nbr < 0)
	{
		is_minus = 1;
		nbr *= -1;
	}
	while (nbr >= base_len)
	{
		*(result + idx) = *(base + (nbr % base_len));
		idx++;
		nbr /= base_len;
	}
	*(result + idx) = *(base + nbr);
	if (is_minus)
	{
		*(result + idx + 1) = '-';
	}
	*(result + idx + 2) = '\0';
}

char	*ft_putnbr_base(long long nbr, char *base)
{
	char		*result;
	int			base_len;

	base_len = ft_check_base(base);
	result = malloc(sizeof(char) * 100);
	ft_putnbr(nbr, base, base_len, result);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*result;
	long long	num;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	result = ft_putnbr_base(num, base_to);
	ft_rev_str(result);
	return (result);
}
