/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:56:08 by edal--ce          #+#    #+#             */
/*   Updated: 2019/11/04 15:56:09 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t			i;
	unsigned char	*c;
	unsigned char	*d;

	c = (unsigned char *)ptr1;
	d = (unsigned char *)ptr2;
	i = 0;
	if (num == 0)
		return (0);
	while (i < num && (c[i] == d[i]))
		i++;
	if (i == num)
		i--;
	return (c[i] - d[i]);
}
