/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:20:14 by jinyoo            #+#    #+#             */
/*   Updated: 2021/04/15 02:52:19 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	cnt_able_sq(char **map, int i, int j, t_inform *inf)
{
	int cnt;
	int x;
	int y;

	if (map[i][j] == inf->object)
		return (0);
	cnt = 1;
	while ((i + cnt < inf->line) && (j + cnt < inf->size))
	{
		x = i + cnt;
		y = j;
		while (y <= j + cnt)
			if (map[x][y++] == inf->object)
				return (cnt);
		x = i;
		y = j + cnt;
		while (x <= i + cnt)
			if (map[x++][y] == inf->object)
				return (cnt);
		cnt++;
	}
	return (cnt);
}

int	**search_sq(char **map, t_inform *inf)
{
	int	i;
	int	j;
	int	**result;

	result = (int**)malloc(sizeof(int*) * inf->line);
	if (!result)
		return (0);
	i = 0;
	while (i < inf->line)
		result[i++] = (int*)malloc(sizeof(int) * inf->size);
	i = 0;
	while (i < inf->line)
	{
		j = 0;
		while (j < inf->size)
		{
			result[i][j] = cnt_able_sq(map, i, j, inf);
			j++;
		}
		i++;
	}
	return (result);
}
