/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 08:30:35 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/22 08:30:39 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_proccessing(char const *s, char c, char **ret, int w)
{
	char	*temp;

	temp = (char*)ft_strnew((int)ft_strlen(ft_strpull_idx(s, c, 0)));
	temp = ft_strpull_idx(s, c, 0);
	ret[w] = ft_strnew(ft_strlen(temp));
	ft_strcpy(ret[w], temp);
	free(temp);
}

char			**ft_strsplit(char const *s, char c)
{
	int		words;
	int		i;
	char	**ret;

	if (!s || !c)
		return (NULL);
	i = 0;
	words = ft_strcount(s, c);
	ret = (char**)malloc(words + 1);
	if (!ret)
		return (NULL);
	while (i < words)
	{
		while (*s == c)
			s++;
		ft_proccessing(s, c, ret, i);
		while (*s != c)
			s++;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
