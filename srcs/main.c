/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:06:53 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/14 20:27:31 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int fd;
	int i;
	int size;
	int tmp;
	char *str;
	char **map;
	t_inform	*inf = malloc(sizeof(t_inform));

	if (argc <= 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	size = read_inform(fd);
	close(fd);

	fd = open(argv[1], O_RDONLY);
	str = read_line(fd, size);
	set_inform(str, inf);

	size = line_size(fd);
	close(fd);

	fd = open(argv[1], O_RDONLY);
	tmp = line_size(fd);
	(void)tmp;

	map = (char **)malloc(sizeof(char*) * (inf->line + 1));
	map[inf->line] = 0;
	i = 0;
	while (i < inf->line)
	{
		map[i] = read_line(fd, size);
		printf("%s\n", map[i]);
		i++;
	}
	return (0);
}
