/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:23:07 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 18:29:20 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;

	if (lst == 0)
		return (lst);
	newlst = 0;
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (newnode)
		{
			ft_lstadd_back(&newlst, newnode);
			lst = lst->next;
		}
		if (!newnode)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
	}
	return (newlst);
}
