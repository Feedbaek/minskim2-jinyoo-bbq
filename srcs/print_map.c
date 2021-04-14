/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:22:01 by jinyoo            #+#    #+#             */
/*   Updated: 2021/04/15 01:29:05 by jinyoo           ###   ########.fr       */
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
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{

			if (max < sq_size[i][j])
			{
				inf.s_size = sq_size[i][j];
				inf.x = j;
				inf.y = i;
			}
			j++;
		}
		i++;
	}
	return (inf);
}

void	convert_map(int **sq_size, t_inform *inf, char **map)
{
	t_box	obj_pt;
	int	i;
	int	j;
	int 	x;
	int	y;
	char	f;

	obj_pt = find_max_size(sq_size, inf->line, inf->size);
	x = obj_pt.x;
	y = obj_pt.y;
	f = inf->full;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((j >= x && j <= x + obj_pt.s_size - 1)\
					&& (i >= y && i <= y + obj_pt.s_size\
						-1))
				map[i][j] = f;
			j++;
		}
		i++;
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
