/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:35:43 by sangylee          #+#    #+#             */
/*   Updated: 2023/02/01 13:06:13 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int	check_min(int x, int y, int d)
{
	if (x <= y && x <= d)
		return (x);
	else if (y <= x && y <= d)
		return (y);
	else
		return (d);
}

void	check_val(int **t, int i, int j, int *max)
{
	int	min;

	if (t[i - 1][j] == -1 || t[i][j - 1] == -1 || t[i - 1][j - 1] == -1)
	{
		t[i][j] = 1;
		min = 0;
	}
	else
	{
		min = check_min(t[i - 1][j], t[i][j - 1], t[i - 1][j - 1]);
		t[i][j] = min + 1;
	}
	if (*max < min + 1)
		*max = min + 1;
}
