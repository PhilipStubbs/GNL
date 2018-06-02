/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:05:32 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/17 08:05:52 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*p1;
	int		i;
	int		e;
	int		size;
	int		max;

	p1 = (char*)src;
	size = ft_strlen(src) + ft_strlen(dest);
	i = 0;
	e = 0;
	max = n;
	while (dest[i] != '\0')
		i++;
	while (i <= size && p1[e] != '\0' && e < max)
	{
		dest[i] = p1[e];
		i++;
		e++;
	}
	dest[i] = '\0';
	return (dest);
}
