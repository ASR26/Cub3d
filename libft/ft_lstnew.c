/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:38:45 by ysmeding          #+#    #+#             */
/*   Updated: 2023/04/20 15:36:34 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_nodeptr;

	new_nodeptr = malloc(sizeof(t_list));
	if (new_nodeptr)
	{
		new_nodeptr->content = content;
		new_nodeptr->next = NULL;
	}
	return (new_nodeptr);
}
