/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:10:17 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/15 14:45:01 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	rush(int x, int y);

int	atoi(char *c)
{
	int	idx;
	int	result;

	idx = 0;
	result = 0;
	while (*(c + idx) != '\0' && *(c + idx) >= '0' && *(c + idx) <= '9')
	{
		result *= 10;
		result += *(c + idx) - '0';
		idx++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (argc == 3)
	{
		x = atoi(*(argv + 1));
		y = atoi(*(argv + 2));
		rush (x, y);
	}
	rush (5, 3);
	rush (5, 1);
	rush (1, 3);
	rush (5, 0);
	rush (0, 5);
	rush (-1, 3);
	rush (5, -1);
	rush (-1, -1);
	return (0);
}
