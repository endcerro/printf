/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:49:01 by edal--ce          #+#    #+#             */
/*   Updated: 2019/11/08 19:49:04 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *cache;
	t_list *cache2;

	cache = *lst;
	while (cache->next)
	{
		cache2 = cache->next;
		ft_lstdelone(cache, del);
		cache = cache2;
	}
	ft_lstdelone(cache, del);
	*lst = 0;
}
