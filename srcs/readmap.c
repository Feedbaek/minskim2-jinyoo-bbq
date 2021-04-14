/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:47:03 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/14 20:17:01 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		read_inform(int fd)
{
	int	cnt;
	char    ch;
	cnt = 0;
	read(fd, &ch, 1);
	while (ch != '\n')
	{
		cnt++;
		read(fd, &ch, 1);
	}
	return (cnt);
}

int		line_size(int fd)  //두번째줄부터
{
	int		cnt;
	char	ch;

	cnt = 0;
	read(fd, &ch, 1);
	while (ch != '\n')
	{
		cnt++;
		read(fd, &ch, 1);
	}
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
