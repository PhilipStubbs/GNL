/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:19:04 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/30 10:19:06 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int			gnlover(t_line *node, char **line)
{
	int		i;

	if (node->overflow)
	{
		if (ft_strchr(node->overflow, '\n'))
		{
			i = ft_strchr_idx(node->overflow, '\n');
			node->overflow[i] = '\0';
			*line = ft_strdup(node->overflow);
			node->overflow = ft_strdup((node->overflow + i) + 1);
			return (1);
		}
		ft_strcat(node->ret, node->overflow);
	}
	return (0);
}

int			gnlreader(char *buff, t_line *node)
{
	int		byter;
	int		i;
	int		j;

	j = 0;
	while ((byter = read(node->fd, buff, BUFF_SIZE)) > 0)
	{
		j++;
		ft_strcat(node->ret, buff);
		if (ft_strchr(buff, '\n'))
		{
			break ;
		}
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	if (byter <= 0)
		return (0);
	if (j > 0)
	{
		i = ft_strchr_idx(node->ret, '\n');
		node->ret[i] = '\0';
		return (1);
	}
	return (0);
}

void		gnlrunthrough(char *buff, t_line *node, char **line)
{
	char	*temp;
	int		tempint;

	if (node->overflow)
		free(node->overflow);
	node->overflow = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE) + 1);
	tempint = (ft_strchr_idx(buff, '\n'));
	temp = ft_strsub(buff, tempint, BUFF_SIZE - tempint);
	ft_memcpy(node->overflow, temp + 1,
		(BUFF_SIZE - ft_strchr_idx(buff, '\n')) + 1);
	free(temp);
	*line = ft_strdup(node->ret);
}

int			gnlchecks(int fd, char **line, t_line *node)
{
	if (!line || fd <= -1 || !node)
		return (-1);
	node->fd = fd;
	if (read(node->fd, 0, 0) == -1)
		return (-1);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_line	*node;
	char			buff[BUFF_SIZE + 1];

	if (!node)
		node = (t_line*)ft_memalloc(sizeof(t_line));
	if (!node->ret)
		node->ret = (char*)ft_memalloc((1000000) * sizeof(char));
	if (((node->isbro = gnlchecks(fd, line, node)) == -1 || node->isbro == 0))
		return (node->isbro);
	ft_bzero(buff, BUFF_SIZE + 1);
	if ((node->gnlo = gnlover(node, line)) == 1)
		return (1);
	node->gnlr = gnlreader(buff, node);
	if (node->gnlr == -1)
		return (-1);
	gnlrunthrough(buff, node, line);
	if (node->gnlr == 0 && node->gnlo == 0 && node->ret[0] == '\0')
	{
		node->ret = NULL;
		node->overflow = NULL;
		return (0);
	}
	ft_strclr(node->ret);
	return (1);
}
