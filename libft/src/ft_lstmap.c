/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:51:39 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 08:17:44 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freelst(t_list *first, void (*del)(void *))
{
	t_list *cache;
	t_list *next;

	cache = first;
	while (cache->next)
	{
		next = cache->next;
		(*del)(cache->content);
		free(cache);
		cache = next;
	}
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *first;
	t_list *current;
	t_list *previous;

	if (!lst)
		return (0);
	first = ft_lstnew((*f)(lst->content));
	previous = first;
	while (lst->next)
	{
		lst = lst->next;
		current = ft_lstnew((*f)(lst->content));
		if (!current)
		{
			freelst(first, del);
			return (first);
		}
		previous->next = current;
		previous = current;
	}
	return (first);
}
