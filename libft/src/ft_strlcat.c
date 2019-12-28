/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:41:37 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 08:18:23 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int posdst;

	posdst = 0;
	while (dst[posdst] && posdst < (int)size)
		posdst++;
	if ((int)size == posdst)
		return (size + ft_strlen(src));
	i = 0;
	while (i + posdst + 1 < (int)size && src[i] != '\0')
	{
		dst[posdst + i] = src[i];
		i++;
	}
	dst[posdst + i] = 0;
	return (posdst + ft_strlen(src));
}
