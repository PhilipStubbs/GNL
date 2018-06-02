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



int    ft_GNLProto()
{

	char buff[BUFF_SIZE + 1];
	static g_list *node;

	int 	byter;
	int 	i;
	char	*ret;
	int		t;

	i = 0;
	t = 0;
	ft_bzero(buff, BUFF_SIZE + 1);
	ret = (char*)ft_memalloc((100 + BUFF_SIZE) * sizeof(char));

	if(!ret)
		return(0);
	if(!node)
		node = (g_list*)ft_memalloc(sizeof(g_list));
	if(!node)
		return(0);
	if(!node->fd)
		node->fd = open("test.txt", O_RDONLY);

	printf("fd : %d\n", node->fd );
	while ((byter = read(node->fd , buff, BUFF_SIZE )) > 0)
	{	
		t +=byter;
		ft_strcat(ret, buff);
		if (ft_strchr(buff, '\n'))
		{
			break;
		}
		ft_bzero(buff, BUFF_SIZE);
	}
		if(byter != 0)
		{
			(*ft_strchr(ret, '\n')) = '\0';
		}

		printf("%d, [%s]\n" ,t,ret);
		free(ret);

	return (0);
}

int	main()
{
	ft_GNLProto();
	ft_GNLProto();
	ft_GNLProto();
	ft_GNLProto();
	ft_GNLProto();
	ft_GNLProto();

}