/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 08:29:37 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/22 08:29:39 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *p)
{
	int		len;
	char	*rp;
	int		i;

	i = 0;
	len = ft_strlen(p);
	rp = (char*)malloc(len);
	if (!rp || !p)
		return (NULL);
	else
	{
		len = len - 1;
		while (len >= 0)
		{
			rp[i] = p[len];
			i++;
			len--;
		}
		i = 0;
		while (rp[i] != '*' && rp[i] != '\0')
			i++;
		rp[i] = '\0';
	}
	return (rp);
}
