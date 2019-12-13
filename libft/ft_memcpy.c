/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:25:29 by edal--ce          #+#    #+#             */
/*   Updated: 2019/11/04 15:25:31 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	unsigned long	i;
	unsigned char	*in;
	unsigned char	*out;

	i = 0;
	in = (unsigned char*)source;
	out = (unsigned char*)destination;
	if ((in == 0 && out == 0))
		return ((void*)source);
	while (i < size)
	{
		out[i] = in[i];
		i++;
	}
	return ((void*)out);
}
