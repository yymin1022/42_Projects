/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:35:37 by yonyoo            #+#    #+#             */
/*   Updated: 2023/10/28 18:20:19 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_file(int argc, char **argv)
{
	if (argc != 2 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		exit_error("Invalid Map Error");
}

void	exit_error(char *str)
{
	ft_printf("Error: %s", str);
	exit(0);
}
