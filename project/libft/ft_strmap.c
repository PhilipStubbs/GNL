/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:54:02 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/17 16:54:04 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	int		i;
	char	*p;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s) + 1;
	p = ft_memalloc(len);
	if (!p)
		return (NULL);
	i = 0;
	while (*s)
	{
		p[i++] = f(*s++);
	}
	p[i] = '\0';
	return (p);
}
