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

// int	get_next_line(const int fd, char **line)
// {
// 	int ret;
// 	char buf[(ret = read(fd, buf, BUFF_SIZ)) > 0];
// }



int    main(int argc, char **argv)
{

	char buff[60000];
	int fd;
	int byter;
	int i;
	static char	*ret;

	i = 0;
	ret = (char*)ft_memalloc(60000 * sizeof(char));
	fd = open("test.txt", O_RDONLY);
	while ((byter = read(fd, buff, 40)) > 0)
	{	
		ft_strcat(ret, buff);
		if (ft_strchr(buff, '\n'))
		{
			break;
		}		
	}
		(*ft_strchr(ret, '\n')) = '\0';
		printf("%d, [%s]\n" ,byter,ret);
		

	return (0);
}
