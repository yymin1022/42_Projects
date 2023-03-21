/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:06:51 by jongmoon          #+#    #+#             */
/*   Updated: 2023/01/29 15:29:56 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char *argv[])
{
	int	res;

	res = 0;
	if (argc == 1)
	{
		res = translate_stdin("numbers.dict");
	}
	else if (argc == 2)
	{
		res = translate("numbers.dict", argv[1]);
	}
	else if (argc == 3)
	{
		res = translate(argv[1], argv[2]);
	}
	if (res == 1)
	{
		ft_putstr("Error\n");
	}
	else if (res == 2)
	{
		ft_putstr("Dict Error!\n");
	}
	return (res);
}
