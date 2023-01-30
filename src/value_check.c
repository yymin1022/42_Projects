/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:35:43 by sangylee          #+#    #+#             */
/*   Updated: 2023/01/30 19:48:22 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq_header.h"

int	check_min(int x, int y, int d)
{
	if (x <= y && x <= d)
		return (x);
	else if (y <= x && y <= d)
		return (y);
	else
		return (d);
}

void	check_val(int **t, int i, int j, int *min_max)
{
	if (t[i - 1][j] == -1 || t[i][j - 1] == -1 || t[i - 1][j - 1] == -1)
		t[i][j] = 1;
	else
	{
		min_max[0] = check_min(t[i - 1][j], t[i][j - 1], t[i - 1][j - 1]);
		t[i][j] = min_max[0] + 1;
		if (min_max[1] < min_max[0] + 1)
			min_max[1] = min_max[0] + 1;
	}
}
