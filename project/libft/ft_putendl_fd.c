/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 08:13:05 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/22 08:13:32 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	*ret;
	int		len;

	if (s)
	{
		len = ft_strlen(s);
		ret = (char*)ft_memalloc(len + 1);
		ft_strcpy(ret, s);
		ret[len] = '\n';
		ret[len + 1] = '\0';
		ft_putstr_fd(ret, fd);
	}
}
