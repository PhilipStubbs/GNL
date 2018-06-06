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
	if (byter <= 0)
		return (0);
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


int		GNLChecks(int fd,char **line, g_list *node)
{

	if(!line || fd <= -1 || !node)
		return(-1);
	node->fd = fd;
	if (read(node->fd, 0, 0) == -1)
		return (-1);
	return (1);
}


int    get_next_line(const int fd, char **line)
{
	static g_list *node;
	char buff[BUFF_SIZE + 1];
	char	*ret;

	if(!node)
		node = (g_list*)ft_memalloc(sizeof(g_list));
	if (((node->isbro = GNLChecks(fd, line, node)) == -1 || node->isbro == 0))
		return (node->isbro);
	ft_bzero(buff, BUFF_SIZE +1);
	ret = (char*)ft_memalloc((52000 + BUFF_SIZE) * sizeof(char));
	if ((node->GNLO = ft_GNLover(ret, buff, node, line)) == 1)
		return(1);
	node->GNLR = ft_GNLReader(ret, buff, node);
	if (node->GNLR == -1)
		return(-1);
	GNLrunthrough(ret, buff, node, line);
	if (node->GNLR == 0 && node->GNLO == 0 && ret[0] == '\0')
	{
		node->overflow = NULL;
		return (0);
	}
	free(ret);
	return(1);
}

// int	main()
// {


// 	// char 	*line;
// 	// int		out;
// 	// int		p[2];
// 	// char 	*str;
// 	// int		len = 50;

// 	// str = (char *)malloc(1000 * 1000);
// 	// *str = '\0';
// 	// while (len--)
// 	// 	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
// 	// out = dup(1);
// 	// pipe(p);
// 	// dup2(p[1], 1);

// 	// if (str)
// 	// 	write(1, str, strlen(str));
// 	// close(p[1]);
// 	// dup2(out, 1);
// 	// get_next_line(p[0], &line);

// 	// // printf(" len : %zu [%s]\n" ,ft_strlen(str), line);
// 	// printf("%d" ,ft_strcmp(line, str));









// 	int i;

// 	char	**line;
// 	int fd = open("test.txt", O_RDONLY);

// 	line = malloc(1000);
// 	*line = malloc(1000);

// 	int fd2 = open("test2.txt", O_RDONLY);
// 	char 	**line2;

// 	line2 = malloc(100000);
// 	*line2 = malloc(100000);
// 	int id;

// 	i = get_next_line(fd, line);
// 	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	ft_bzero(*line,100 );


// 	id = get_next_line(fd2, line2);
// 	printf("%d : len : %zu [%s]\n",id ,ft_strlen(*line2), *line2);
// 	// ft_bzero(*line,1000 );
// 	// 	id = get_next_line(fd2, line2);
// 	// printf("%d : len : %zu [%s]\n",id ,ft_strlen(*line2), *line2);

// 	// 	id = get_next_line(fd2, line2);
// 	// printf("%d : len : %zu [%s]\n",id ,ft_strlen(*line2), *line2);
// 	// i = get_next_line(-10000, NULL);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// // // ft_bzero(*line,100 );

// 	// i = get_next_line(1, NULL);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// // // ft_bzero(*line,100 );

// 	// i = get_next_line(99, NULL);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);

// 	// i = get_next_line(-99, &line2);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// // ft_bzero(*line,100 );

// 	// i = get_next_line(-1, &line2);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// // ft_bzero(*line,100 );

// 	// 	i = get_next_line(-10000, &line2);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// // // ft_bzero(*line,100 );

// 	// 	i = get_next_line(42, &line2);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// // ft_bzero(*line,100 );

// 	// 	i = get_next_line(fd, line);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// // ft_bzero(*line,100 );
// 	// 	i = get_next_line(fd, line);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// 		i = get_next_line(fd, line);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// 		i = get_next_line(fd, line);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// 		i = get_next_line(fd, line);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// 		i = get_next_line(fd, line);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// 		i = get_next_line(fd, line);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// 		i = get_next_line(fd, line);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// 		i = get_next_line(fd, line);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// 		i = get_next_line(fd, line);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// 	// 		i = get_next_line(fd, line);
// 	// printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);


// 	// ft_bzero(*line,100 );
	

// }

// 0abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz25
// 0abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmn0abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmn0abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcde