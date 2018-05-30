/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:06:40 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/17 08:06:44 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*p1;
	int		i;
	int		size;

	p1 = (char*)src;
	i = 0;
	size = n;
	while (src[i] != '\0' && i < size)
	{
		dest[i] = p1[i];
		i++;
	}
	while (i != (int)n)
		dest[i++] = '\0';
	return (dest);
}
