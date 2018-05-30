/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 08:41:56 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/18 08:41:57 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*p;

	if (s1 != NULL && s2 != NULL)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		p = ft_memalloc(len);
		if (p == NULL)
			return (NULL);
		if (p == NULL)
			return (NULL);
		i = 0;
		while (*s1)
		{
			p[i++] = *s1++;
		}
		while (*s2)
		{
			p[i++] = *s2++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
