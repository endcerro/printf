/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:50:59 by edal--ce          #+#    #+#             */
/*   Updated: 2019/11/04 15:51:04 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	size_t	i;
	char	*c;

	c = (char *)ptr;
	i = 0;
	while (i < num)
	{
		if (c[i] == value)
			return ((void*)&c[i]);
		i++;
	}
	return (0);
}
