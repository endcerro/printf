/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:45:56 by edal--ce          #+#    #+#             */
/*   Updated: 2019/11/07 15:45:57 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	size_t	i;
	size_t	size;

	if (!s || !f)
		return (0);
	size = ft_strlen(s);
	i = 0;
	if (!(out = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (s[i])
	{
		out[i] = (*f)(i, s[i]);
		i++;
	}
	out[i] = 0;
	return (out);
}
