/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:47:03 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/14 23:12:13 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	line_size(int fd, int *first, int *map_size)
{
	char	ch;

	*first = 0;
	*map_size = 0;
	read(fd, &ch, 1);
	while (ch != '\n' && ch != 0)
	{
		(*first)++;
		read(fd, &ch, 1);
	}
	read(fd, &ch, 1);
	while (ch != '\n' && ch != 0)
	{
		(*map_size)++;
		read(fd, &ch, 1);
	}
}

char	*read_line(int fd, int line_size)
{
	char ch;
	char *p;
	char *tmp;

	p = (char *)malloc(sizeof(char) * line_size + 1);
	if (!p)
		return (0);
	tmp = p;
	read(fd, &ch, 1);
	while (ch != '\n')
	{
		*tmp = ch;
		read(fd, &ch, 1);
		tmp++;
	}
	*tmp = 0;
	return (p);	
}

void	set_inform(char *inform, t_inform *map)
{
	int idx;
	int i;

	idx = ft_strlen(inform) - 1;
	i = 0;
	map->full = inform[idx--];
	map->object = inform[idx--];
	map->empty = inform[idx--];
	map->line = 0;
	while (i <= idx)
	{
		map->line *= 10;
		map->line += inform[i] - '0';
		i++;
	}
}
