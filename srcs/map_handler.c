/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:20:14 by jinyoo            #+#    #+#             */
/*   Updated: 2021/04/14 18:27:09 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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
	}
}


