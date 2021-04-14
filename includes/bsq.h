/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:26:33 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/14 18:06:32 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putchar(char c);
void    ft_putstr(char *str);
int		line_size(void);
char    *read_line(int fd, int line_size);
int		ft_strlen(char *str);

typedef struct	s_inform
{
	int		line;
	char	empty;
	char	full;
	char	object;
}		t_inform;

typedef struct	s_box
{
	int	x;
	int	y;
	int	square_size;
}		t_box;

//define

#endif
