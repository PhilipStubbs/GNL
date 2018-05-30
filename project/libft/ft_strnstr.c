/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:08:26 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/17 08:08:30 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*p1;
	int		i;
	int		j;

	p1 = (char*)haystack;
	i = 0;
	if (ft_strcmp(needle, "") == 0)
		return (p1);
	while (haystack[i] != '\0' && i <= (int)len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && (j + i != (int)len))
		{
			if (needle[j + 1] == '\0')
				return ((char*)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
