/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:47:49 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/17 17:47:53 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;
	char			*p1;
	char			*p2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if ((ft_strcmp(s1, "") == 0 && ft_strcmp(s2, "") == 0) || n == 0)
		return (1);
	p1 = ft_strsub(s1, 0, n);
	p2 = ft_strsub(s2, 0, n);
	i = ft_strcmp(p1, p2);
	if (i == 0)
		return (1);
	else
		return (0);
	return (0);
}
