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

// int	get_next_line(const int fd, char **line)
// {
// 	int ret;
// 	char buf[(ret = read(fd, buf, BUFF_SIZ)) > 0];
// }



int    ft_GNLProto(int arc, char **arv)
{
	char buff[BUFF_SIZE + 1];
	static g_list *node;

	int 	byter;
	int 	i;
	char	*ret;
	int		t;
	int 	count;
	int 	len;


	i = 0;
	t = 0;
	count = 0;
	ft_bzero(buff, BUFF_SIZE + 1);
	ret = (char*)ft_memalloc((100 + BUFF_SIZE) * sizeof(char));

	if(!ret)
		return(0);

	if(!node)
		node = (g_list*)ft_memalloc(sizeof(g_list));

	if(!node)
		return(0);

	if (arc == 1)
		node->fd = 1;

	if(node->overflow)
		ft_strcat(ret, node->overflow);

	if(!node->fd)
		node->fd = open(arv[1], O_RDONLY);
	
	while ((byter = read(node->fd , buff, BUFF_SIZE )) > 0)
	{
		count++;
		ft_strcat(ret, buff);
		if (ft_strchr(buff, '\n'))
		{
			break;
		}
		t +=byter;
		ft_bzero(buff, BUFF_SIZE);
	}
	
	if(byter != 0)
	{
		i = ft_strchr_idx(ret, '\n');
		ret[i] = '\0';
	}

	count *= BUFF_SIZE;
	printf("[byter :%d], [count : %d] ,[i : %d],[%s]\n" ,t,count ,i,ret);
	if(node->overflow)
		free(node->overflow);
	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
	ft_memcpy(node->overflow, (ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) +1,BUFF_SIZE )), (BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);

	// printf("%s\n", buff);
	// printf("%s\n", node->overflow);
	free(ret);

	return(0);
}

int	main(int arc, char **arv)
{
	ft_GNLProto(arc, arv);
	ft_GNLProto(arc, arv);
	ft_GNLProto(arc, arv);
	ft_GNLProto(arc, arv);
	ft_GNLProto(arc, arv);

}
// There once was a bunny named Humphrey
// That lived in a house that was comfy
// He was once a pet
// With a knife he was met
// And he was delicious

// {
// 	char buff[BUFF_SIZE + 1];
// 	static g_list *node;

// 	int 	byter;
// 	int 	i;
// 	char	*ret;
// 	int		t;
// 	int 	count;
// 	int 	len;
// 	char	*temp;
// 	char	*temptr;

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
// 		// printf("%s\n", node->overflow);
// 		ft_strcat(ret, node->overflow);
// 	}
// 	if(!node->fd)
// 	{
// 		node->fd = open(arv[1], O_RDONLY);
// 		// printf("fd : %d\n", node->fd );
// 	}

	
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
// 	printf("[byter :%d], [count : %d] ,[i : %d],[%s]\n" ,t,count ,i,ret);
// 	if(node->overflow)
// 		free(node->overflow);
// 	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
// 	// len = BUFF_SIZE - ft_strchr_idx(buff , '\n') +1;
// 	len = (count - i) +1;
// 	// printf("BUFF : [%s], count - i : [%d],  len : [%d]\n",buff, (count - i), len);
// 	// printf("count,[%d],  i : [%d]\n",count ,i);
// 	// if (count >= i)
// 	// {
// 		ft_memcpy(node->overflow, (ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) +1,BUFF_SIZE )), (BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);
// 	// }

// 	// if(i > count)
// 	// {
// 	// 	node->overflow = (char*)ft_memalloc(BUFF_SIZE);
// 	// 	temptr = ft_strchr(buff, '\n') + 1;
// 	// 	ft_memcpy(node->overflow , temptr, (BUFF_SIZE - ft_strchr_idx(buff, '\n')));
// 	// }

// 	// printf("%s\n", buff);
// 	// printf("%s\n", node->overflow);
// 	free(ret);

// 	return(0);
// }

