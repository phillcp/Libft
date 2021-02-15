/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:03:41 by fheaton-          #+#    #+#             */
/*   Updated: 2021/02/15 14:39:36 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*ret;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		if (!(ret = ft_lstnew((*f)(lst->content))))
		{
			while (first)
			{
				ret = first->next;
				(*del)(first->content);
				free(first);
				first = ret;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, ret);
		lst = lst->next;
	}
	return (first);
}
