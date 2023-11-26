/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:28:12 by yonyoo            #+#    #+#             */
/*   Updated: 2023/11/26 15:18:15 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arr_len(char **arr, int *size)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	*size = i;
}

static int	is_dup(int num, t_list *stk)
{
	while (stk)
	{
		if (stk->num == num)
			return (1);
			stk = stk->next;
	}
	return (0);
}

static int	is_long(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '+' || str[1] == '-')
		i++;
	while (str[i] == '0')
		i++;
	j = 0;
	while (str[i])
	{
		i++;
		j++;
	}
	return (j < 11);
}

static int is_valid(char *str, t_list **stk){
	int			i;
	long long	tmp;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (!is_long(str))
		return (0);
	tmp = ft_atoll(str);
	if (tmp > 2147483647 || tmp < -2147483648)
		return (0);
	if (is_dup(tmp, *stk))
		return (0);
	return (1);
}

static void	parse_list(char *str, t_list **stk)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		exit_err("Memory Error");
	if (!is_valid(str, stk))
		exit_err("Invalid Argument");
	tmp->num = ft_atoll(str);
	tmp->next = 0;
	ft_lstadd_back(stk, tmp);
}

int	parse_input(int argc, char **argv, t_stk *stk)
{
	int		i;
	int		j;
	int		size;
	char	**arr;

	stk->top = 0;
	i = 1;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		arr_len(arr, &size);
		if (!arr || size == 0)
			exit_err("Failed to parse input");
		j = 0;
		while (j < size)
		{
			parse_list(arr[j], &(stk->top));
			(stk->size)++;
			free(arr[j]);
			j++;
		}
		free(arr);
		i++;
	}
	return (stk->size);
}
