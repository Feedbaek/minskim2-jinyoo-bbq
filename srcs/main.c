/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:06:53 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/15 12:24:36 by jinyoo           ###   ########.fr       */
/*   Updated: 2021/04/15 11:13:30 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		bsq(int fd, t_inform *inf)
{
	int		i;
	char	**map;
	int		**result;
	int		j;

	map = (char **)malloc(sizeof(char*) * (inf->line + 1));
	if (!map)
		exit(1);
	map[inf->line] = 0;
	i = 0;
	while (i < inf->line)
	{
		j = 0;
		map[i] = read_line(fd, inf->size);
		while (map[i][j])
		{
			if (map[i][j] != inf->empty && map[i][j] != \
					inf->object)
				return (0);
			j++;
		}
		i++;
	}
	result = search_sq(map, inf);
	convert_map(result, inf, map);
	free(result);
	print_map(map);
	return (1);
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
	if(!bsq(fd, inf))
	{
		print_error();
		return ;
	}
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
	i = 1;
	if (argc == 1)
	{
		fd = open("./Test", O_TRUNC | O_WRONLY|O_CREAT, 0644);
		while (read(0, &c, 1))
			write(fd, &c, 1);
		close(fd);
		argv[1] = "./Test";
		set_bsq(1, inf, argv);
	}
	else
	{
		while (i < argc)
		{
			set_bsq(i, inf, argv);
			if (i < argc - 1)
				ft_putchar('\n');
			i++;
		}
	}
	free(inf);
	return (0);
}
