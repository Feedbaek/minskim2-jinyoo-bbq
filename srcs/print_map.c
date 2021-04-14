/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:22:01 by jinyoo            #+#    #+#             */
/*   Updated: 2021/04/15 01:45:53 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_box	find_max_size(int **sq_size, int h, int w)
{
	int 	max;
	int 	i;
	int 	j;
	t_box	inf;

	max = -1;
	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
		{

			if (max < sq_size[i][j])
			{
				max = sq_size[i][j];
				inf.s_size = max;
				inf.x = j;
				inf.y = i;
			}
		}
	}
	return (inf);
}

void	convert_map(int **sq_size, t_inform *inf, char **map)
{
	t_box	box_pt;
	int 	width;
	int	height;
	char	f;

	box_pt = find_max_size(sq_size, inf->line, inf->size);
	height = box_pt.y;
	f = inf->full;
	while (height < box_pt.y + box_pt.s_size)
	{
		width = box_pt.x;
		while (width < box_pt.x + box_pt.s_size)
			map[height][width++] = f;
		height++;
	}	
}

void	print_map(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			write(1, &map[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}
