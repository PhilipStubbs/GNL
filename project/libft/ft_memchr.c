/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 07:46:04 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/17 07:46:07 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*p1;

	p1 = (unsigned char*)src;
	ch = c;
	while (n--)
	{
		if (*p1 == ch)
			return (p1);
		p1++;
	}
	return (NULL);
}
