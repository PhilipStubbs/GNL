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

	char buff[BUFF_SIZE +1];
	static int fd;
	int byter;
	int i;
	char	*ret;
	// static int j;
	// static int e;

	i = 0;
	ft_bzero(buff, BUFF_SIZE + 1);
	ret = (char*)ft_memalloc(100 * sizeof(char));
	if(!ret)
		return(0);
	if(!fd)
		fd = open("test.txt", O_RDONLY);
	while ((byter = read(fd, buff, BUFF_SIZE )) > 0)
	{	
		write(1, "x" ,1 );
		i +=byter;
		ft_strcat(ret, buff);
		if (ft_strchr(buff, '\n' || ft_strchr(buff, EOF ))
		{
			write(1, "e" ,1 );
			break;
		}
		ft_bzero(buff, BUFF_SIZE);
	}
		(*ft_strchr(ret, '\n')) = '\0';

		printf("%d, [%s]\n" ,i,ret);
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
}