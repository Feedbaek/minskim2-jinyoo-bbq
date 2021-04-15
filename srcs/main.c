/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:06:53 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/15 10:37:54 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	bsq(int fd, t_inform *inf)
{
	int		i;
	char	**map;
	int		**result;

	map = (char **)malloc(sizeof(char*) * (inf->line + 1));
	if (!map)
		return ;
	map[inf->line] = 0;
	i = 0;
	while (i < inf->line)
		map[i++] = read_line(fd, inf->size);
	result = search_sq(map, inf);
	convert_map(result, inf, map);
	free(result);
	print_map(map);
}

void	set_bsq(int i, t_inform *inf, char *argv[])
{
	int			fd;
	int			first;
	int			size;
	char		*str;

	fd = open(argv[i], O_RDONLY);
	line_size(fd, &first, &size);
	close(fd);
	fd = open(argv[i], O_RDONLY);
	str = read_line(fd, first);
	set_inform(str, inf);
	inf->size = size;
	bsq(fd, inf);
	close(fd);
	free(str);
}

int		main(int argc, char *argv[])
{
	int			i;
	t_inform	*inf;

	inf = (t_inform*)malloc(sizeof(t_inform));
	if (!inf || argc <= 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		set_bsq(i, inf, argv);
		ft_putchar('\n');
		i++;
	}
	free(inf);
	return (0);
}
