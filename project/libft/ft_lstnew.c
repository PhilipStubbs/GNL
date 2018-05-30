/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:00:54 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/28 09:00:56 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *link;

	link = (t_list*)ft_memalloc(sizeof(t_list));
	if (!link)
		return (NULL);
	if (!content)
	{
		link->content = ft_memalloc(sizeof(NULL));
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		link->content = ft_memalloc(content_size);
		if (!link->content)
			return (NULL);
		ft_memcpy(link->content, content, content_size);
		link->content_size = content_size;
	}
	link->next = NULL;
	return (link);
}
