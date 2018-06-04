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

int		ft_GNLoverflow(char *ret, char *buff, g_list *node)
{	
	int i = 0;
	
	if(node->overflow)
	{
		if(ft_strchr(node->overflow, '\n'))
		{	
			ft_strcat(ret, node->overflow);
			i = ft_strchr_idx(ret, '\n');
			ret[i] = '\0';
			free(ret);
			ret = ft_memalloc(i);
			ft_memcpy(ret, node->overflow, i);
			if (i < BUFF_SIZE)					// write the info back into the overflow
			{	
				ft_memcpy(buff, (node->overflow + i) +1, (BUFF_SIZE - i));
				ft_memcpy(node->overflow, buff, (BUFF_SIZE - i));
			}
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
	if(node->overflow)
		free(node->overflow);
	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
	ft_memcpy(node->overflow, (ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) +1,BUFF_SIZE )), 
		(BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);

	// line = (char**)ft_memalloc(sizeof(char)*ft_strlen(ret));
	ft_memcpy()
	
	//write into the line;

}





int    get_next_line(const int fd, char **line)
{
	static g_list *node;
	char buff[BUFF_SIZE + 1];
	int 	GNLR;
	int		GNLO;
	char	*ret;

	ret = (char*)ft_memalloc((100 + BUFF_SIZE) * sizeof(char));
	if(!line || !fd)
		return(-1);
	if(!node)
		node = (g_list*)ft_memalloc(sizeof(g_list));
	if(!node)
		return(-1);
	node->fd = fd;
	if ((GNLO = ft_GNLoverflow(ret, buff, node)) == 1)
		return(1);
	GNLR = ft_GNLReader(ret, buff, node);
	GNLrunthrough(ret, buff,node, line);
		// printf("[%s]\n" ,ret);
	free(ret);
	if (GNLR == 0 && GNLO == 0)
	{
		node->overflow = NULL;
		return (0);
	}
	return(1);
}

int	main()
{
	int i;
	int fd = open("test.txt", O_RDONLY);
	char	**line;
	line = malloc(1);

	i = get_next_line(fd, &line);
	printf("%d\n",i );
	i = get_next_line(fd, &line);
	printf("%d\n",i );
	i = get_next_line(fd, &line);
	printf("%d\n",i );
	i = get_next_line(fd, &line);
	printf("%d\n",i );
	i = get_next_line(fd, &line);
	printf("%d\n",i );
	i = get_next_line(fd, &line);
	printf("%d\n",i );
	i = get_next_line(fd, &line);
	printf("%d\n",i );
	i = get_next_line(fd, &line);
	printf("%d\n",i );
	i = get_next_line(fd, &line);
	printf("%d\n",i );
	// printf("[%d] : [%s] \n" ,i, *line);
	

}
