/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:07:13 by jongmoon          #+#    #+#             */
/*   Updated: 2023/01/29 15:25:08 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_entry
{
	int		digit;
	int		unit;
	char	*value;
}	t_entry;

typedef struct s_list
{
	struct s_list	*next;
	t_entry			*data;
}	t_list;

typedef enum e_print_option
{
	NO_SPACE,
	ONLY_SPACE,
	HYPHEN,
	COMMA,
	AND_LETTERS
}	t_print_option;

void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_str_is_numeric(char *str);

int		translate(char *dict_name, char *input);
int		translate_stdin(char *dict_name);
int		convert_raw(t_list *root, char *input);
char	*trim_input(char *input);
int		find_max_unit(t_list *root);

int		get_dict_size(char *dict);
char	*read_dict(char *dict);
t_list	*make_dict_list(char *file);

t_list	*create_elem(int digit, int unit, char *value);
int		push_back(t_list *root, int digit, int unit, char *value);
void	free_list(t_list *root);

int		parse(char *file, t_list *root);
int		get_digit(char *file, int *digit);
int		get_unit(char *file, int digit, int *unit);
int		get_value(char *file, char **value);
char	*dup_len(char *file, int len);

void	convert(t_list *root, char *str, int len);
void	convert_period(t_list *root, char *str, int period);
void	convert_period_2(t_list *root, char *str);
void	print_value(t_list *root, int digit, int unit, t_print_option opt_new);
char	*find_value(t_list *root, int digit, int unit);

#endif
