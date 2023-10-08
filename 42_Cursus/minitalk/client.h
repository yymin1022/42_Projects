/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:51:39 by yonyoo            #+#    #+#             */
/*   Updated: 2023/10/08 17:29:04 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(char *str);
char	*ft_strjoin(char *str, char *append);
size_t	ft_strlen(char *str);
void	ft_put_str(char *str);

#endif
