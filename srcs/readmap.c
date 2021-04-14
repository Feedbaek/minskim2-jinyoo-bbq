/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:47:03 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/14 17:10:38 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		line_size(void)
{
	int cnt;
	int fd;

	cnt = 0;
	fd = open(fd, O_RDONLY);
	read(fd, &ch, 1);
	while (ch != '\n')
		cnt++;
	close(fd);
	return (cnt);
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
