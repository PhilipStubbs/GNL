/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:03:00 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/17 08:03:02 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dest, const char *restrict src, size_t len)
{
	char		*s;
	int			i;
	int			e;
	unsigned	ret;

	s = (char*)src;
	i = 0;
	e = 0;
	ret = ft_strlen(dest) + ft_strlen(src);
	if (len < ft_strlen(dest) + 1)
		return (ft_strlen(src) + len);
	else
	{
		while (dest[i] != '\0')
			i++;
		while (i < ((int)len - 1))
		{
			dest[i++] = s[e++];
		}
		dest[i] = '\0';
	}
	return (ret);
}
