/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 07:10:58 by pstubbs           #+#    #+#             */
/*   Updated: 2018/06/01 07:11:00 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_idx(const char *str, int c)
{
	char			*p1;
	unsigned char	ch;
	int				i;

	i = 0;
	p1 = (char*)str;
	ch = c;
	while (p1[i] != ch)
	{
		if (p1[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}
