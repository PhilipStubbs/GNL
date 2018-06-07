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
			
			// *line = ft_strdup(node->ret);
			// ft_bzero(node->ret, ft_strlen(node->ret));
			// free(ret);
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
	// if(node->ret)
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
		node->ret = (char*)ft_memalloc((550000) * sizeof(char));
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





// #include "get_next_line.h"

// #include <stdio.h>

// int			gnlover(char *ret, t_line *node, char **line)
// {
// 	int		i;

// 	if (node->overflow)
// 	{
// 		if (ft_strchr(node->overflow, '\n'))
// 		{
// 			i = ft_strchr_idx(node->overflow, '\n');
// 			node->overflow[i] = '\0';
// 			*line = ft_strdup(node->overflow);
// 			// if (i < BUFF_SIZE)
// 			// {
// 				node->overflow  = ft_strdup((node->overflow + i) + 1);
// 			// }
// 			// *line = ft_strdup(ret);
// 			// free(ret);
// 			return (1);
// 		}
// 		ft_strcat(ret, node->overflow);
// 	}
// 	return (0);
// }

// int			gnlreader(char *ret, char *buff, t_line *node)
// {
// 	int		byter;
// 	int		i;
// 	int		j;

// 	j = 0;
// 	while ((byter = read(node->fd, buff, BUFF_SIZE)) > 0)
// 	{
// 		j++;
// 		ft_strcat(ret, buff);
// 		if (ft_strchr(buff, '\n'))
// 		{
// 			break ;
// 		}
// 		ft_bzero(buff, BUFF_SIZE + 1);
// 	}
// 	if (byter <= 0)
// 		return (0);
// 	if (j > 0)
// 	{
// 		i = ft_strchr_idx(ret, '\n');
// 		ret[i] = '\0';
// 		return (1);
// 	}
// 	return (0);
// }

// void		gnlrunthrough(char *ret, char *buff, t_line *node, char **line)
// {
// 	char	*temp;
// 	int		tempint;

// 	if (node->overflow)
// 		free(node->overflow);
// 	node->overflow = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE) + 1);
// 	tempint = (ft_strchr_idx(buff, '\n'));
// 	temp = ft_strsub(buff, tempint, BUFF_SIZE - tempint);
// 	ft_memcpy(node->overflow, temp + 1,
// 		(BUFF_SIZE - ft_strchr_idx(buff, '\n')) + 1);
// 	free(temp);
// 	*line = ft_strdup(ret);
// }

// int			gnlchecks(int fd, char **line, t_line *node)
// {
// 	if (!line || fd <= -1 || !node)
// 		return (-1);
// 	node->fd = fd;
// 	if (read(node->fd, 0, 0) == -1)
// 		return (-1);
// 	return (1);
// }

// int			get_next_line(const int fd, char **line)
// {
// 	static t_line	*node;
// 	char			buff[BUFF_SIZE + 1];
// 	char			*ret;

// 	if (!node)
// 		node = (t_line*)ft_memalloc(sizeof(t_line));
// 	if (((node->isbro = gnlchecks(fd, line, node)) == -1 || node->isbro == 0))
// 		return (node->isbro);
// 	ft_bzero(buff, BUFF_SIZE + 1);
// 	ret = (char*)ft_memalloc((550000) * sizeof(char));
// 	if ((node->gnlo = gnlover(ret, node, line)) == 1)
// 		return (1);
// 	node->gnlr = gnlreader(ret, buff, node);
// 	if (node->gnlr == -1)
// 		return (-1);
// 	gnlrunthrough(ret, buff, node, line);
// 	if (node->gnlr == 0 && node->gnlo == 0 && ret[0] == '\0')
// 	{
// 		node->overflow = NULL;
// 		return (0);
// 	}
// 	free(ret);
// 	return (1);
// }





// #include "get_next_line.h"

// #include <stdio.h>

// int			gnlover(char *ret, char *buff, t_line *node, char **line)
// {
// 	int		i;

// 	if (node->overflow)
// 	{
// 		if (ft_strchr(node->overflow, '\n'))
// 		{
// 			ft_strcat(ret, node->overflow);
// 			i = ft_strchr_idx(ret, '\n');
// 			ret[i] = '\0';
// 			ft_memcpy(ret, node->overflow, i);
// 			if (i < BUFF_SIZE)
// 			{
// 				ft_memcpy(buff, (node->overflow + i) + 1, (BUFF_SIZE - i));
// 				ft_memcpy(node->overflow, buff, (BUFF_SIZE - i));
// 			}
// 			*line = ft_strdup(ret);
// 			free(ret);
// 			return (1);
// 		}
// 		ft_strcat(ret, node->overflow);
// 	}
// 	return (0);
// }

// int			gnlreader(char *ret, char *buff, t_line *node)
// {
// 	int		byter;
// 	int		i;
// 	int		j;

// 	j = 0;
// 	while ((byter = read(node->fd, buff, BUFF_SIZE)) > 0)
// 	{
// 		j++;
// 		ft_strcat(ret, buff);
// 		if (ft_strchr(buff, '\n'))
// 		{
// 			break ;
// 		}
// 		ft_bzero(buff, BUFF_SIZE + 1);
// 	}
// 	if (byter <= 0)
// 		return (0);
// 	if (j > 0)
// 	{
// 		i = ft_strchr_idx(ret, '\n');
// 		ret[i] = '\0';
// 		return (1);
// 	}
// 	return (0);
// }

// void		gnlrunthrough(char *ret, char *buff, t_line *node, char **line)
// {
// 	char	*temp;
// 	int		tempint;

// 	if (node->overflow)
// 		free(node->overflow);
// 	node->overflow = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE) + 1);
// 	tempint = (ft_strchr_idx(buff, '\n'));
// 	temp = ft_strsub(buff, tempint, BUFF_SIZE - tempint);
// 	ft_memcpy(node->overflow, temp + 1,
// 		(BUFF_SIZE - ft_strchr_idx(buff, '\n')) + 1);
// 	free(temp);
// 	*line = ft_strdup(ret);
// }

// int			gnlchecks(int fd, char **line, t_line *node)
// {
// 	if (!line || fd <= -1 || !node)
// 		return (-1);
// 	node->fd = fd;
// 	if (read(node->fd, 0, 0) == -1)
// 		return (-1);
// 	return (1);
// }

// int			get_next_line(const int fd, char **line)
// {
// 	static t_line	*node;
// 	char			buff[BUFF_SIZE + 1];
// 	char			*ret;

// 	if (!node)
// 		node = (t_line*)ft_memalloc(sizeof(t_line));
// 	if (((node->isbro = gnlchecks(fd, line, node)) == -1 || node->isbro == 0))
// 		return (node->isbro);
// 	ft_bzero(buff, BUFF_SIZE + 1);
// 	ret = (char*)ft_memalloc((500000 + BUFF_SIZE) * sizeof(char));
// 	if ((node->gnlo = gnlover(ret, buff, node, line)) == 1)
// 		return (1);
// 	node->gnlr = gnlreader(ret, buff, node);
// 	if (node->gnlr == -1)
// 		return (-1);
// 	gnlrunthrough(ret, buff, node, line);
// 	if (node->gnlr == 0 && node->gnlo == 0 && ret[0] == '\0')
// 	{
// 		node->overflow = NULL;
// 		return (0);
// 	}
// 	free(ret);
// 	return (1);
// }
