/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:47:12 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 08:18:30 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	char	*cp;
	size_t	i;

	i = 0;
	out = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start || len == 0)
		return (ft_strdup(""));
	if (!(out = malloc(sizeof(char) * (len + 1))))
		return (0);
	cp = out;
	while (s[start + i] && i < len)
		*(out++) = s[start + i++];
	*out = 0;
	return (cp);
}
