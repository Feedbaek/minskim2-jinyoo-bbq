/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:06:53 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/15 11:25:48 by jinyoo           ###   ########.fr       */
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
		exit(1);
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
	if(!set_inform(str, inf))
	{
		print_error();
		return ;
	}
	inf->size = size;
	bsq(fd, inf);
	close(fd);
	free(str);
}

int		main(int argc, char *argv[])
{
	int			i;
	int			fd;
	char		c;
	t_inform	*inf;

	inf = (t_inform*)malloc(sizeof(t_inform));
	if (!inf)
		exit(1);
	if (argc == 1)
	{
		fd = open("./Test", O_TRUNC|O_WRONLY|O_CREAT, 0644);
		while (read(0, &c, 1)
				write(fd, &c, 1);
	}
	i = 1;
	while (i < argc)
	{
		set_bsq(i, inf, argv);
		if (i < argc - 1)
			ft_putchar('\n');
		i++;
	}
	free(inf);
	return (0);
}
