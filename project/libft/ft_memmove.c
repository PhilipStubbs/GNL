/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 07:49:28 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/17 07:49:29 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*p1;
	unsigned char			*p2;

	p1 = (unsigned char*)dest;
	p2 = (unsigned char*)src;
	if (p2 < p1)
	{
		while (n--)
		{
			p1[n] = p2[n];
		}
	}
	else
		ft_memcpy(p1, p2, n);
	return (p1);
}
