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

int		ft_GNLoverflow(char *ret, char *buff, g_list *node, char **line)
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
			if (i < BUFF_SIZE)					// write the info back into the overflow
			{	
				ft_memcpy(buff, (node->overflow + i) +1, (BUFF_SIZE - i));
				ft_memcpy(node->overflow, buff, (BUFF_SIZE - i));
			}
			*line = ft_strdup(ret);
			free(ret);
			return (1);
		}
	ft_strcat(ret, node->overflow);
	// *line = ft_strdup(ret);
	}
	return(0);	
}


int		ft_GNLReader(char *ret, char *buff, g_list *node)
{
	int 	byter;
	int 	i;
	int		j;

	j = 0;
	i = 0;
	while ((byter = read(node->fd , buff, BUFF_SIZE )) > 0)
	{
		j++;
		// printf("%d\n",byter );
		ft_strcat(ret, buff);
		if (ft_strchr(buff, '\n'))
		{
			break;
		}
		ft_bzero(buff, BUFF_SIZE +1);
	}

	// printf("byter:  %d\n",byter);
	if(j > 0)
	{
		i = ft_strchr_idx(ret, '\n');
		ret[i] = '\0';
		return (1);
	}
	return(0);
}



void		GNLrunthrough(char *buff, g_list *node)
{
	char	*temp;

	if(node->overflow)
		free(node->overflow);
	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
	temp = ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) ,BUFF_SIZE );
	ft_memcpy(node->overflow, temp + 1, (BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);
	free(temp);
	// ft_memcpy(node->overflow, (ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) +1,BUFF_SIZE )), 
	// 	(BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);


}


// There once was a bunny named Humphrey
// That lived in a house that was comfy
// He was once a pet
// With a knife he was met
// And he was delicious


int    get_next_line(const int fd, char **line)
{
	static g_list *node;
	char buff[BUFF_SIZE + 1];
	char	*ret;

	if(!node)
	{	
		node = (g_list*)ft_memalloc(sizeof(g_list));
		node->i = 0;
	}
	ft_bzero(buff, BUFF_SIZE +1);
	if(!line || fd <= -1 || !node)
		return(-1);
	ret = (char*)ft_memalloc((100 + BUFF_SIZE) * sizeof(char));
	node->fd = fd;
	if ((node->GNLO = ft_GNLoverflow(ret, buff, node, line)) == 1)
		return(1);
	node->GNLR = ft_GNLReader(ret, buff, node);
	GNLrunthrough(buff, node);
	*line = ft_strdup(ret);
	free(ret);
	if (node->GNLR == 0 && node->GNLO == 0)
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

	// i = get_next_line(fd, line);
	// printf("%d : [%s]\n",i , *line);
	

}
