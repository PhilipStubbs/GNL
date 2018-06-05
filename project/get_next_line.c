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

int		ft_GNLover(char *ret, char *buff, g_list *node, char **line)
{	
	int i = 0;
	
	if(node->overflow)
	{
		if(ft_strchr(node->overflow, '\n'))
		{	
			ft_strcat(ret, node->overflow);
			i = ft_strchr_idx(ret, '\n');
			ret[i] = '\0';
			ft_memcpy(ret, node->overflow, i);
			if (i < BUFF_SIZE)				
			{	
				ft_memcpy(buff, (node->overflow + i) +1, (BUFF_SIZE - i));
				ft_memcpy(node->overflow, buff, (BUFF_SIZE - i));
			}
			*line = ft_strdup(ret);
			free(ret);
			return (1);
		}
	ft_strcat(ret, node->overflow);
	}
	return(0);	
}


int		ft_GNLReader(char *ret, char *buff, g_list *node)
{
	int 	byter;
	int 	i;
	int		j;

	j = 0;
	while ((byter = read(node->fd , buff, BUFF_SIZE )) > 0)
	{
		j++;
		ft_strcat(ret, buff);
		if (ft_strchr(buff, '\n'))
		{
			break;
		}
		ft_bzero(buff, BUFF_SIZE +1);
	}
	if(j > 0)
	{
		i = ft_strchr_idx(ret, '\n');
		ret[i] = '\0';
		return (1);
	}
	return(0);
}



void		GNLrunthrough(char *ret, char *buff, g_list *node, char **line)
{
	char	*temp;

	if(node->overflow)
		free(node->overflow);
	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
	temp = ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) ,BUFF_SIZE );
	ft_memcpy(node->overflow, temp + 1, (BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);
	free(temp);
	*line = ft_strdup(ret);
}


int    get_next_line(const int fd, char **line)
{
	static g_list *node;
	char buff[BUFF_SIZE + 1];
	char	*ret;

	if(!node)
		node = (g_list*)ft_memalloc(sizeof(g_list));
	if(!line || fd <= -1 || !node)
		return(-1);
	if (node->isfin == 1)
		return(0);
	ft_bzero(buff, BUFF_SIZE +1);
	ret = (char*)ft_memalloc((100 + BUFF_SIZE) * sizeof(char));
	node->fd = fd;
	if ((node->GNLO = ft_GNLover(ret, buff, node, line)) == 1)
		return(1);
	node->GNLR = ft_GNLReader(ret, buff, node);
	GNLrunthrough(ret, buff, node, line);
	if (node->GNLR == 0 && node->GNLO == 0 && ret[0] == '\0')
	{
		node->isfin = 1;
		node->overflow = NULL;
		return (0);
	}
	free(ret);
	return(1);
}

int	main()
{
	int i;
	int fd = open("test.txt", O_RDONLY);
	char	**line;
	line = malloc(1000);
	*line = malloc(1000);


	i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
	// ft_bzero(*line,100 );


	i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
	// ft_bzero(*line,1000 );

	i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
	// ft_bzero(*line,100 );

	i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
	// ft_bzero(*line,100 );

	i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);

	i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
	// ft_bzero(*line,100 );
	i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
	// ft_bzero(*line,100 );
		i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
	// ft_bzero(*line,100 );

		i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
	// ft_bzero(*line,100 );

		i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
	// ft_bzero(*line,100 );
		i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
			i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
			i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
			i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
			i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
			i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
			i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
			i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
			i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
			i = get_next_line(fd, line);
	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);


	// ft_bzero(*line,100 );
	

}
