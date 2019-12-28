/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:35:18 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 08:18:01 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t size)
{
	unsigned long	i;
	unsigned char	*in;
	unsigned char	*out;

	i = 0;
	in = (unsigned char*)source;
	out = (unsigned char*)destination;
	while (i < size)
	{
		out[i] = in[i];
		if (out[i] == (unsigned char)c)
			return (void*)(&out[i + 1]);
		i++;
	}
	return (0);
}
