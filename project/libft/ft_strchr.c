/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 07:52:40 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/17 07:52:45 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char			*p1;
	unsigned char	ch;

	p1 = (char*)str;
	ch = c;
	while (*p1 != ch)
	{
		if (*p1 == '\0')
			return (p1 = NULL);
		p1++;
	}
	return (p1);
}
