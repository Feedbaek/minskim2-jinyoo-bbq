/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:06:53 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/14 21:15:11 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int fd;
	int first;
	int size;
	int i;
	char *str;
	char **map;
	t_inform	*inf;
	
	inf = (t_inform*)malloc(sizeof(t_inform));
	if (argc <= 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	line_size(fd, &first, &size);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	str = read_line(fd, first);
	set_inform(str, inf);
	map = (char **)malloc(sizeof(char*) * (inf->line + 1));
	map[inf->line] = 0;
	i = 0;
	while (i < inf->line)
		map[i++] = read_line(fd, size);
	return (0);
}
