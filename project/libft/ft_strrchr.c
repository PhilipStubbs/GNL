/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:09:43 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/17 08:09:46 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*p1;
	int		len;

	len = ft_strlen(str);
	p1 = (char*)str;
	if (c == '\0')
		return (p1 + len);
	while (len >= 0)
	{
		if (p1[len] != c)
			len--;
		else
			return (p1 + len);
	}
	return (p1 = NULL);
}
