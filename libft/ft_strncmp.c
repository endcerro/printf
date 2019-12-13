/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:36:10 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/03 17:34:58 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1t;
	unsigned char	*s2t;

	s1t = (unsigned char *)s1;
	s2t = (unsigned char *)s2;
	i = 0;
	while (s1t[i] == s2t[i] && i < n && s2t[i] && s1t[i])
	{
		if (s1t[i] != s2t[i])
			return (s1t[i] - s2t[i]);
		i++;
	}
	if ((s1t[i] != s2t[i]) && i < n)
		return ((s1t[i] - s2t[i]));
	return (0);
}
