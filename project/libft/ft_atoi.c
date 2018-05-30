/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 07:32:42 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/17 07:32:49 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int	i;
	int				in;
	int				c;

	i = 0;
	in = 0;
	while ((str[in] == '\n') || (str[in] == '\t') || (str[in] == '\v') ||
			(str[in] == ' ') || (str[in] == '\f') || (str[in] == '\r'))
	{
		in++;
	}
	c = in;
	while (str[in] == '-' || str[in] == '+')
		in++;
	if ((str[in - 1] == '-' || str[in - 1] == '+') &&
		(str[in - 2] == '-' || str[in - 2] == '+'))
	{
		return (0);
	}
	while (str[in] >= '0' && str[in] <= '9')
		i = (i * 10) + (str[in++] - '0');
	if (str[c] == '-')
		i *= -1;
	return (i);
}
