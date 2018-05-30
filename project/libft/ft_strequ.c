/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:31:28 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/17 17:31:29 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	i;
	int s1len;
	int s2len;

	i = 0;
	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (ft_strcmp(s1, "") == 0 && ft_strcmp(s2, "") == 0)
		return (1);
	if (s1len != s2len)
		return (0);
	i = ft_strcmp(s1, s2);
	if (i == 0)
		return (1);
	else
		return (0);
	return (0);
}
