/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:26:33 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/15 03:04:31 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			line_size(int fd, int *first, int *map_size);
char			*read_line(int fd, int line_size);
int				ft_strlen(char *str);

typedef	struct	s_inform
{
	char	empty;
	char	full;
	char	object;
	int		line;
	int		size;
}				t_inform;

void			set_inform(char *inform, t_inform *map);
int				**search_sq(char **map, t_inform *inf);

typedef struct	s_box
{
	int	x;
	int	y;
	int	s_size;
}				t_box;

t_box			find_max_size(int **sq_size, int h, int w);
void			convert_map(int **sq_size, t_inform *inf, char **map);
void			print_map(char **map);
void			bsq(int fd, t_inform *inf);

#endif
