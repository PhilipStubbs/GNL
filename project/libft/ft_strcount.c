/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 08:19:58 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/22 08:20:02 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcount(char const *s, char d)
{
	int		i;
	int		count;
	int		len;

	len = ft_strlen(s);
	i = 0;
	count = 0;
	while (i < len)
	{
		while (s[i] == d && s[i] != '\0')
			i++;
		while (s[i] != d && s[i] != '\0')
			i++;
		if (s[i - 1] != d)
			count++;
	}
	return (count);
}
