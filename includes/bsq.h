/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:26:33 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/14 20:16:07 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putchar(char c);
void    ft_putstr(char *str);
int		read_inform(int fd);
int		line_size(int fd);
char    *read_line(int fd, int line_size);
int		ft_strlen(char *str);

typedef struct	s_inform
{
	int		line;
	char	empty;
	char	full;
	char	object;
}		t_inform;

void    set_inform(char *inform, t_inform *map);

typedef struct	s_box
{
	int	x;
	int	y;
	int	square_size;
}		t_box;

//define

#endif
