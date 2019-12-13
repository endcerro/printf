/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:41:37 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/03 18:59:48 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int posdst;
	int possrc;

	posdst = 0;
	while (dst[posdst] && posdst < (int)size)
		posdst++;
	if ((int)size == posdst)
		return (size + ft_strlen(src));
	possrc = 0;
	i = 0;
	while (i + posdst + 1 < (int)size && src[i] != '\0')
	{
		dst[posdst + i] = src[i];
		i++;
	}
	dst[posdst + i] = 0;
	return (posdst + ft_strlen(src));
}
