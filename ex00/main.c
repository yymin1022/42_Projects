/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:26:33 by yonyoo            #+#    #+#             */
/*   Updated: 2023/01/21 11:38:03 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_arg(char *arg);
void	print_err(int err);

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_err(0);
		return (0);
	}
	if (!check_arg(argv[0]))
	{
		print_err(1);
		return (0);
	}
	return (0);
}
