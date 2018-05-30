/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpull_idx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:28:17 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/28 09:28:19 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpull_idx(const char *s, char c, unsigned int start)
{
	int	i;
	int	wordlen;

	i = 0;
	while (i < (int)start)
	{
		s++;
		i++;
	}
	wordlen = ft_wordlen((s), c);
	while (*s == c)
	{
		i++;
		s++;
	}
	return (ft_strsub(s, 0, wordlen));
}
