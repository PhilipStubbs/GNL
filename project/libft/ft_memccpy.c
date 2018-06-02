/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 07:43:53 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/17 07:43:55 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*p1;
	unsigned int	i;

	if (!n)
		return (NULL);
	i = 0;
	p1 = (unsigned char*)dest;
	while (i < n)
	{
		*(p1 + i) = *((char *)src + i);
		if (*((unsigned char*)src + i) == (unsigned char)c)
		{
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
