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
		node->bytesRe += byter;
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
	int		tempint;

	if(node->overflow)
		free(node->overflow);
	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
	tempint = (int)(ft_strchr_idx(buff , '\n')) ;
	temp = ft_strsub(buff,tempint ,BUFF_SIZE - tempint);
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
	ret = (char*)ft_memalloc((50000 + BUFF_SIZE) * sizeof(char));
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
// 	// printf("%d" ,ft_strcmp(line, "0abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz25"));


// 	int i;

// 	// int fd = open("test.txt", O_RDONLY);

// 	// line = malloc(1000);
// 	// *line = malloc(1000);

// 	int fd2 = open("one_big_fat_line.txt", O_RDONLY);
// 	char 	**line2;
// 	// char	**line;
// 	line2 = malloc(100000);
// 	*line2 = malloc(100000);
// 	// int id;

// 	i = get_next_line(fd2, line2);
// 	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line2), *line2);




// }

// 0abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz25
// 0abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz250abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwxyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz11abcdefghijklmnopqrstuvwxyz12abcdefghijklmnopqrstuvwxyz13abcdefghijklmnopqrstuvwxyz14abcdefghijklmnopqrstuvwxyz15abcdefghijklmnopqrstuvwxyz16abcdefghijklmnopqrstuvwxyz17abcdefghijklmnopqrstuvwxyz18abcdefghijklmnopqrstuvwxyz19abcdefghijklmnopqrstuvwxyz20abcdefghijklmnopqrstuvwxyz21abcdefghijklmnopqrstuvwxyz22abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz23abcdefghijklmnopqrstuvwxyz24abcdefghijklmnopqrstuvwxyz25
// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2018/05/30 10:19:04 by pstubbs           #+#    #+#             */
// /*   Updated: 2018/05/30 10:19:06 by pstubbs          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// #include <stdio.h>

// int		ft_GNLoverflow(char *ret, char *buff, g_list *node, char **line)
// {	
// 	int i = 0;
	
// 	if(node->overflow)
// 	{
// 		if(ft_strchr(node->overflow, '\n'))
// 		{	
// 			ft_strcat(ret, node->overflow);
// 			i = ft_strchr_idx(ret, '\n');
// 			ret[i] = '\0';
// 			free(ret);
// 			ret = ft_memalloc(i);
// 			ft_memcpy(ret, node->overflow, i);
// 			if (i < BUFF_SIZE)					// write the info back into the overflow
// 			{	
// 				ft_memcpy(buff, (node->overflow + i) +1, (BUFF_SIZE - i));
// 				ft_memcpy(node->overflow, buff, (BUFF_SIZE - i));
// 			}
// 			*line = ft_strdup(ret);
// 			free(ret);
// 			return (1);
// 		}
// 	ft_strcat(ret, node->overflow);
// 	// *line = ft_strdup(ret);
// 	}
// 	return(0);	
// }


// int		ft_GNLReader(char *ret, char *buff, g_list *node)
// {
// 	int 	byter;
// 	int 	i;
// 	int		j;

// 	j = 0;
// 	i = 0;
// 	while ((byter = read(node->fd , buff, BUFF_SIZE )) > 0)
// 	{
// 		j++;
// 		// printf("%d\n",byter );
// 		ft_strcat(ret, buff);
// 		if (ft_strchr(buff, '\n'))
// 		{
// 			break;
// 		}
// 		ft_bzero(buff, BUFF_SIZE +1);
// 	}

// 	// printf("byter:  %d\n",byter);
// 	if(j > 0)
// 	{
// 		i = ft_strchr_idx(ret, '\n');
// 		ret[i] = '\0';
// 		return (1);
// 	}
// 	return(0);
// }



// void		GNLrunthrough(char *buff, g_list *node)
// {

// 	if(node->overflow)
// 		free(node->overflow);
// 	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
// 	ft_memcpy(node->overflow, (ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) +1,BUFF_SIZE )), 
// 		(BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);




// }


// // There once was a bunny named Humphrey
// // That lived in a house that was comfy
// // He was once a pet
// // With a knife he was met
// // And he was delicious


// int    get_next_line(const int fd, char **line)
// {
// 	static g_list *node;
// 	char buff[BUFF_SIZE + 1];
// 	int 	GNLR;
// 	int		GNLO;
// 	char	*ret;

// 	if(!node)
// 	{	
// 		node = (g_list*)ft_memalloc(sizeof(g_list));
// 		node->i = 0;
// 	}
// 	ft_bzero(buff, BUFF_SIZE +1);
// 	if(!line || fd <= -1 || !node)
// 		return(-1);
// 	ret = (char*)ft_memalloc((100 + BUFF_SIZE) * sizeof(char));
// 	node->fd = fd;
// 	if ((GNLO = ft_GNLoverflow(ret, buff, node, line)) == 1)
// 		return(1);
// 	GNLR = ft_GNLReader(ret, buff, node);
// 	GNLrunthrough(buff, node);

// 	*line = ft_strdup(ret);
// 	free(ret);
// 	if (GNLR == 0 && GNLO == 0)
// 	{
// 		node->overflow = NULL;
// 		return (0);
// 	}
// 	return(1);
// }

// // int	main()
// // {
// // 	int i;
// // 	int fd = open("test.txt", O_RDONLY);
// // 	char	**line;
// // 	line = malloc(1000);
// // 	*line = malloc(1000);


// // 	i = get_next_line(fd, line);
// // 	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// // 	// ft_bzero(*line,100 );


// // 	i = get_next_line(fd, line);
// // 	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// // 	// ft_bzero(*line,1000 );

// // 	i = get_next_line(fd, line);
// // 	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// // 	// ft_bzero(*line,100 );

// // 	i = get_next_line(fd, line);
// // 	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// // 	// ft_bzero(*line,100 );

// // 	i = get_next_line(fd, line);
// // 	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);

// // 	i = get_next_line(fd, line);
// // 	printf("%d : len : %zu [%s]\n",i ,ft_strlen(*line), *line);
// // 	// ft_bzero(*line,100 );

// // 	// i = get_next_line(fd, line);
// // 	// printf("%d : [%s]\n",i , *line);
	

// // }







































// int		ft_GNLoverflow(char *ret, char *buff, g_list *node)
// {	
// 	int i = 0;
	
// 	if(node->overflow)
// 	{
// 		if(ft_strchr(node->overflow, '\n'))
// 		{	
// 			ft_strcat(ret, node->overflow);
// 			i = ft_strchr_idx(ret, '\n');
// 			ret[i] = '\0';
// 			free(ret);
// 			ret = ft_memalloc(i);
// 			ft_memcpy(ret, node->overflow, i);
// 			if (i < BUFF_SIZE)					// write the info back into the overflow
// 			{	
// 				ft_memcpy(buff, (node->overflow + i) +1, (BUFF_SIZE - i));
// 				ft_memcpy(node->overflow, buff, (BUFF_SIZE - i));
// 			}
// 			return (1);
// 		}
// 	ft_strcat(ret, node->overflow);
// 	}
// 	return(0);	
// }






// int		ft_GNLReader(char *ret, char *buff, g_list *node)
// {
// 	int 	byter;
// 	int 	i;

// 	while ((byter = read(node->fd , buff, BUFF_SIZE )) > 0)
// 	{
// 		ft_strcat(ret, buff);
// 		if (ft_strchr(buff, '\n'))
// 		{
// 			break;
// 		}
// 	}
// 	if(byter != 0)
// 	{
// 		i = ft_strchr_idx(ret, '\n');
// 		ret[i] = '\0';
// 		return (1);
// 	}
// 	return(0);
// }





// void		GNLrunthrough(char *ret, char *buff, g_list *node)
// {
// 	if(node->overflow)
// 		free(node->overflow);
// 	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
// 	ft_memcpy(node->overflow, (ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) +1,BUFF_SIZE )), 
// 		(BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);
// 	free(ret);

// }

// int    get_next_line(const int fd, char **line)
// {
// 	static g_list *node;
// 	char buff[BUFF_SIZE + 1];
// 	int 	GNLR;
// 	int		GNLO;
// 	char	*ret;

// 	ret = (char*)ft_memalloc((100 + BUFF_SIZE) * sizeof(char));
// 	if(!line || !fd)
// 		return(-1);
// 	if(!node)
// 		node = (g_list*)ft_memalloc(sizeof(g_list));
// 	if(!node)
// 		return(-1);
// 	node->fd = fd;
// 	if ((GNLO = ft_GNLoverflow(ret, buff, node)) == 1)
// 		return(1);
// 	GNLR = ft_GNLReader(ret, buff, node);
// 	GNLrunthrough(ret, buff,node);
// 	if (GNLR == 0 && GNLO == 0)
// 	{
// 		free(node);
// 		return (0);
// 	}
// 	printf("[%s]\n" ,ret);
// 	return(1);
// }





















// /* ************************************************************************** */
                                                                            
//                                                         :::      ::::::::   
// /*   get_next_line.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2018/05/30 10:19:04 by pstubbs           #+#    #+#             */
// /*   Updated: 2018/05/30 10:19:06 by pstubbs          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// #include <stdio.h>

// int		ft_GNLoverflow(char *ret, char *buff, g_list *node)
// {	
// 	int i = 0;
	
// 	if(node->overflow)
// 	{
// 		if(ft_strchr(node->overflow, '\n'))
// 		{	
// 			ft_strcat(ret, node->overflow);
// 			i = ft_strchr_idx(ret, '\n');
// 			ret[i] = '\0';
// 			free(ret);
// 			ret = ft_memalloc(i);
// 			ft_memcpy(ret, node->overflow, i);
// 			if (i < BUFF_SIZE)					// write the info back into the overflow
// 			{	
// 				ft_memcpy(buff, (node->overflow + i) +1, (BUFF_SIZE - i));
// 				ft_memcpy(node->overflow, buff, (BUFF_SIZE - i));
// 			}
// 			return (1);
// 		}
// 	ft_strcat(ret, node->overflow);
// 	}
// 	return(0);	
// }






// int		ft_GNLReader(char *ret, char *buff, g_list *node)
// {
// 	int 	byter;
// 	int 	i;

// 	while ((byter = read(node->fd , buff, BUFF_SIZE )) > 0)
// 	{
// 		ft_strcat(ret, buff);
// 		if (ft_strchr(buff, '\n'))
// 		{
// 			break;
// 		}
// 	}
// 	if(byter != 0)
// 	{
// 		i = ft_strchr_idx(ret, '\n');
// 		ret[i] = '\0';
// 		return (1);
// 	}
// 	return(0);
// }





// void		GNLrunthrough(char *ret, char *buff, g_list *node)
// {
// 	if(node->overflow)
// 		free(node->overflow);
// 	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
// 	ft_memcpy(node->overflow, (ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) +1,BUFF_SIZE )), 
// 		(BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);
// 	free(ret);

// }





// int    get_next_line(const int fd, char **line)
// {
// 	static g_list *node;
// 	char buff[BUFF_SIZE + 1];
// 	int 	GNLR;
// 	int		GNLO;
// 	char	*ret;

// 	ft_bzero(buff, BUFF_SIZE + 1);
// 		write(1, "a\n",2);
// 	ret = (char*)ft_memalloc((100 + BUFF_SIZE) * sizeof(char));
// 	if(!line || !fd)
// 		return(-1);
// 	if(!node)
// 		node = (g_list*)ft_memalloc(sizeof(g_list));
		
// 	if(!node)
// 		return(-1);
// 	node->fd = fd;
// 	if ((GNLO = ft_GNLoverflow(ret, buff, node)) == 1)
// 	{
// 		printf("[%s]\n" ,ret);
// 		return(1);
// 	}

// 	GNLR = ft_GNLReader(ret, buff, node);
// 	GNLrunthrough(ret, buff,node);
// 	if (GNLR == 0 && GNLO == 0)
// 	{
// 		free(node);
// 		ft_bzero(buff, BUFF_SIZE + 1);
// 		return (0);
// 	}
// 	return(1);
// }

// int	main()
// {
// 	int i;
// 	int fd = open("test.txt", O_RDONLY);
// 	printf("%d\n", fd);
// 	char	**line;
// 	line = malloc(1);

// 	i = get_next_line(fd, line);
// 	i = get_next_line(fd, line);
// 	i = get_next_line(fd, line);
// 	i = get_next_line(fd, line);
// 	i = get_next_line(fd, line);
// 	i = get_next_line(fd, line);
// 	i = get_next_line(fd, line);
// 	// printf("[%d] : [%s] \n" ,i, *line);
	

// }


// // int    ft_GNLProto(int arc, char **arv)
// // {
// // 	static g_list *node;
// // 	char buff[BUFF_SIZE + 1];
// // 	int 	GNLR;
// // 	int		GNLO;
// // 	char	*ret;

// // 	ft_bzero(buff, BUFF_SIZE + 1);
// // 	ret = (char*)ft_memalloc((100 + BUFF_SIZE) * sizeof(char));
// // 	if(!ret)
// // 		return(-1);
// // 	if(!node)
// // 		node = (g_list*)ft_memalloc(sizeof(g_list));
// // 	if(!node)
// // 		return(-1);
// // 	if (arc == 1)
// // 		node->fd = 1;
// // 	if ((GNLO = ft_GNLoverflow(ret, buff, node)) == 1)
// // 	{
// // 		printf("[%s]\n" ,ret);
// // 		return(1);
// // 	}
// // 	if(!node->fd)
// // 		node->fd = open(arv[1], O_RDONLY);

// // 	GNLR = ft_GNLReader(ret, buff, node);
// // 	printf("[%s]\n" ,ret);
// // 	if(node->overflow)
// // 		free(node->overflow);
// // 	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
// // 	ft_memcpy(node->overflow, (ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) +1,BUFF_SIZE )), 
// // 		(BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);
// // 	free(ret);
// // 	if (GNLR == 0 && GNLO == 0)
// // 	{
// // 		free(node);
// // 		ft_bzero(buff, BUFF_SIZE + 1);
// // 		return (0);
// // 	}
// // 	return(1);
// // }

// // There once was a bunny named Humphrey
// // That lived in a house that was comfy
// // He was once a pet
// // With a knife he was met
// // And he was delicious

// // int    ft_GNLProto(int arc, char **arv)
// // {
// // 	char buff[BUFF_SIZE + 1];
// // 	static g_list *node;

// // 	int 	byter;
// // 	int 	i;
// // 	char	*ret;
// // 	int		t;
// // 	int 	count;


// // 	i = 0;
// // 	t = 0;
// // 	count = 0;
// // 	ft_bzero(buff, BUFF_SIZE + 1);
// // 	ret = (char*)ft_memalloc((100 + BUFF_SIZE) * sizeof(char));

// // 	if(!ret)
// // 		return(0);

// // 	if(!node)
// // 		node = (g_list*)ft_memalloc(sizeof(g_list));

// // 	if(!node)
// // 		return(0);

// // 	if (arc == 1)
// // 		node->fd = 1;


// // 	if(node->overflow)
// // 	{
// // 		if(ft_strchr(node->overflow, '\n'))
// // 			{	
// // 				ft_strcat(ret, node->overflow);
// // 				i = ft_strchr_idx(ret, '\n');
// // 				ret[i] = '\0';
// // 				ft_memcpy(ret, node->overflow, i);
// // 				if (i < BUFF_SIZE)					// write the info back into the overflow
// // 				{	
// // 					ft_memcpy(buff, (node->overflow + i) +1, (BUFF_SIZE - i));
// // 					ft_memcpy(node->overflow, buff, (BUFF_SIZE - i));
// // 					printf("[byter :%d], [count : %d] ,[i : %d],	[%s]\n" ,t,count ,i,ret);
// // 					return(0);
// // 				}
// // 			}
// // 		else
// // 			ft_strcat(ret, node->overflow);
// // 	}

// // 	if(!node->fd)
// // 		node->fd = open(arv[1], O_RDONLY);
	
// // 	while ((byter = read(node->fd , buff, BUFF_SIZE )) > 0)
// // 	{
// // 		count++;
// // 		ft_strcat(ret, buff);
// // 		if (ft_strchr(buff, '\n'))
// // 		{
// // 			break;
// // 		}
// // 		t +=byter;
// // 		ft_bzero(buff, BUFF_SIZE);
// // 	}
	
// // 	if(byter != 0)
// // 	{
// // 		i = ft_strchr_idx(ret, '\n');
// // 		ret[i] = '\0';
// // 	}

// // 	count *= BUFF_SIZE;
// // 	printf("[byter :%d], [count : %d] ,[i : %d],	[%s]\n" ,t,count ,i,ret);
// // 	if(node->overflow)
// // 		free(node->overflow);
// // 	node->overflow = (char*)ft_memalloc(sizeof(char)*(BUFF_SIZE) + 1);
// // 	ft_memcpy(node->overflow, (ft_strsub(buff,(int)(ft_strchr_idx(buff , '\n')) +1,BUFF_SIZE )), (BUFF_SIZE - ft_strchr_idx(buff , '\n')) +1);
// // 	free(ret);

// // 	return(0);
// // }