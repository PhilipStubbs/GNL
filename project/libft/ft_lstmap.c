/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:07:33 by pstubbs           #+#    #+#             */
/*   Updated: 2018/05/28 11:07:34 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	ret = f(lst);
	if (!ret)
		return (NULL);
	temp = ret;
	lst = lst->next;
	while (lst != NULL)
	{
		temp->next = f(lst);
		temp = temp->next;
		lst = lst->next;
	}
	return (ret);
}
