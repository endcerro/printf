/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:48:53 by edal--ce          #+#    #+#             */
/*   Updated: 2019/11/13 21:34:58 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	char	*cp;
	int		sz;

	sz = 1;
	if (s1)
		sz += ft_strlen(s1);
	if (s2)
		sz += ft_strlen(s2);
	if (!s1 && !s2)
		return (0);
	if (!(out = malloc(sizeof(char) * sz)))
		return (0);
	cp = out;
	if (s1--)
		while (*(++s1))
			*(out++) = *s1;
	if (s2--)
		while (*(++s2))
			*(out++) = *s2;
	*out = 0;
	return (cp);
}
