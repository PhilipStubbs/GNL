/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:10:44 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/17 08:10:46 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*p1;
	char	*p2;
	int		i;

	p2 = (char*)needle;
	p1 = (char*)haystack;
	i = 0;
	if (ft_strcmp(needle, "") == 0)
		return (p1);
	while (1)
	{
		if (p2[i] == p1[i])
		{
			if (p2[i + 1] == '\0')
				return (p1);
			i++;
		}
		else
		{
			i = 0;
			if (p1[i] == '\0')
				return (p1 = NULL);
			p1++;
		}
	}
}
