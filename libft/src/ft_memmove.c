/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:38:42 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 08:18:08 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (dst == 0 && src == 0)
		return (dst);
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	if (s < d)
		while (++i <= n)
			d[n - i] = s[n - i];
	else
		while (n-- > 0)
			*(d++) = *(s++);
	return (dst);
}
