/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:19:09 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/30 10:19:14 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <fcntl.h>//5000000
# define BUFF_SIZE 50000
typedef	struct		s_line
{
	char			*overflow;
	char			*ret;
	int				fd;
	int				gnlr;
	int				gnlo;
	int				isbro;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
