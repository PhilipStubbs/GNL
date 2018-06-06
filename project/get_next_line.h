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
# include <fcntl.h>
				// 10000000
# define BUFF_SIZE 20
//117 - 138
typedef	struct		a_list
{
	char			*overflow;
	int				fd;
	int				GNLR;
	int				GNLO;
	int				isbro;
}					g_list;

int	get_next_line(const int fd, char **line);

#endif
