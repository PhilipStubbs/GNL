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

	while ((byter = read(node->fd , buff, BUFF_SIZE )) > 0)
	{
		ft_strcat(ret, buff);
		if (ft_strchr(buff, '\n'))
		{
			break;
		}
	}
	if(byter != 0)
	{
		i = ft_strchr_idx(ret, '\n');
		ret[i] = '\0';
		return (1);
	}
	return(0);
}





void		GNLrunthrough(char *ret, char *buff, g_list *node)
{
	if(node->overflow)
		free(node->overflow);
	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
	ft_memcpy(node->overflow, (ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) +1,BUFF_SIZE )), 
		(BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);
	free(ret);

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
	GNLrunthrough(ret, buff,node);
	if (GNLR == 0 && GNLO == 0)
	{
		free(node);
		return (0);
	}
	printf("[%s]\n" ,ret);
	return(1);
}





















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

	while ((byter = read(node->fd , buff, BUFF_SIZE )) > 0)
	{
		ft_strcat(ret, buff);
		if (ft_strchr(buff, '\n'))
		{
			break;
		}
	}
	if(byter != 0)
	{
		i = ft_strchr_idx(ret, '\n');
		ret[i] = '\0';
		return (1);
	}
	return(0);
}





void		GNLrunthrough(char *ret, char *buff, g_list *node)
{
	if(node->overflow)
		free(node->overflow);
	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
	ft_memcpy(node->overflow, (ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) +1,BUFF_SIZE )), 
		(BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);
	free(ret);

}





int    get_next_line(const int fd, char **line)
{
	static g_list *node;
	char buff[BUFF_SIZE + 1];
	int 	GNLR;
	int		GNLO;
	char	*ret;

	ft_bzero(buff, BUFF_SIZE + 1);
		write(1, "a\n",2);
	ret = (char*)ft_memalloc((100 + BUFF_SIZE) * sizeof(char));
	if(!line || !fd)
		return(-1);
	if(!node)
		node = (g_list*)ft_memalloc(sizeof(g_list));
		
	if(!node)
		return(-1);
	node->fd = fd;
	if ((GNLO = ft_GNLoverflow(ret, buff, node)) == 1)
	{
		printf("[%s]\n" ,ret);
		return(1);
	}

	GNLR = ft_GNLReader(ret, buff, node);
	GNLrunthrough(ret, buff,node);
	if (GNLR == 0 && GNLO == 0)
	{
		free(node);
		ft_bzero(buff, BUFF_SIZE + 1);
		return (0);
	}
	return(1);
}

int	main()
{
	int i;
	int fd = open("test.txt", O_RDONLY);
	printf("%d\n", fd);
	char	**line;
	line = malloc(1);

	i = get_next_line(fd, line);
	i = get_next_line(fd, line);
	i = get_next_line(fd, line);
	i = get_next_line(fd, line);
	i = get_next_line(fd, line);
	i = get_next_line(fd, line);
	i = get_next_line(fd, line);
	// printf("[%d] : [%s] \n" ,i, *line);
	

}


// int    ft_GNLProto(int arc, char **arv)
// {
// 	static g_list *node;
// 	char buff[BUFF_SIZE + 1];
// 	int 	GNLR;
// 	int		GNLO;
// 	char	*ret;

// 	ft_bzero(buff, BUFF_SIZE + 1);
// 	ret = (char*)ft_memalloc((100 + BUFF_SIZE) * sizeof(char));
// 	if(!ret)
// 		return(-1);
// 	if(!node)
// 		node = (g_list*)ft_memalloc(sizeof(g_list));
// 	if(!node)
// 		return(-1);
// 	if (arc == 1)
// 		node->fd = 1;
// 	if ((GNLO = ft_GNLoverflow(ret, buff, node)) == 1)
// 	{
// 		printf("[%s]\n" ,ret);
// 		return(1);
// 	}
// 	if(!node->fd)
// 		node->fd = open(arv[1], O_RDONLY);

// 	GNLR = ft_GNLReader(ret, buff, node);
// 	printf("[%s]\n" ,ret);
// 	if(node->overflow)
// 		free(node->overflow);
// 	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
// 	ft_memcpy(node->overflow, (ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) +1,BUFF_SIZE )), 
// 		(BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);
// 	free(ret);
// 	if (GNLR == 0 && GNLO == 0)
// 	{
// 		free(node);
// 		ft_bzero(buff, BUFF_SIZE + 1);
// 		return (0);
// 	}
// 	return(1);
// }

// There once was a bunny named Humphrey
// That lived in a house that was comfy
// He was once a pet
// With a knife he was met
// And he was delicious

// int    ft_GNLProto(int arc, char **arv)
// {
// 	char buff[BUFF_SIZE + 1];
// 	static g_list *node;

// 	int 	byter;
// 	int 	i;
// 	char	*ret;
// 	int		t;
// 	int 	count;


// 	i = 0;
// 	t = 0;
// 	count = 0;
// 	ft_bzero(buff, BUFF_SIZE + 1);
// 	ret = (char*)ft_memalloc((100 + BUFF_SIZE) * sizeof(char));

// 	if(!ret)
// 		return(0);

// 	if(!node)
// 		node = (g_list*)ft_memalloc(sizeof(g_list));

// 	if(!node)
// 		return(0);

// 	if (arc == 1)
// 		node->fd = 1;


// 	if(node->overflow)
// 	{
// 		if(ft_strchr(node->overflow, '\n'))
// 			{	
// 				ft_strcat(ret, node->overflow);
// 				i = ft_strchr_idx(ret, '\n');
// 				ret[i] = '\0';
// 				ft_memcpy(ret, node->overflow, i);
// 				if (i < BUFF_SIZE)					// write the info back into the overflow
// 				{	
// 					ft_memcpy(buff, (node->overflow + i) +1, (BUFF_SIZE - i));
// 					ft_memcpy(node->overflow, buff, (BUFF_SIZE - i));
// 					printf("[byter :%d], [count : %d] ,[i : %d],	[%s]\n" ,t,count ,i,ret);
// 					return(0);
// 				}
// 			}
// 		else
// 			ft_strcat(ret, node->overflow);
// 	}

// 	if(!node->fd)
// 		node->fd = open(arv[1], O_RDONLY);
	
// 	while ((byter = read(node->fd , buff, BUFF_SIZE )) > 0)
// 	{
// 		count++;
// 		ft_strcat(ret, buff);
// 		if (ft_strchr(buff, '\n'))
// 		{
// 			break;
// 		}
// 		t +=byter;
// 		ft_bzero(buff, BUFF_SIZE);
// 	}
	
// 	if(byter != 0)
// 	{
// 		i = ft_strchr_idx(ret, '\n');
// 		ret[i] = '\0';
// 	}

// 	count *= BUFF_SIZE;
// 	printf("[byter :%d], [count : %d] ,[i : %d],	[%s]\n" ,t,count ,i,ret);
// 	if(node->overflow)
// 		free(node->overflow);
// 	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
// 	ft_memcpy(node->overflow, (ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) +1,BUFF_SIZE )), (BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);
// 	free(ret);

// 	return(0);
// }