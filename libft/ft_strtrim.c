/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:54:40 by edal--ce          #+#    #+#             */
/*   Updated: 2019/11/07 15:54:41 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isincharset(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}

static int		getfinalsize(char const *s1, char const *set, int *start)
{
	int i;
	int cpt;
	int end;

	end = -1;
	cpt = 0;
	i = 0;
	while (s1[i] && isincharset(s1[i], set))
		i++;
	*start = i;
	while (s1[i])
	{
		if (isincharset(s1[i], set) && end == -1)
			end = i;
		else if (!isincharset(s1[i], set))
			end = -1;
		i++;
	}
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	int		start;
	int		end;
	char	*cp;

	if (!s1 || !set)
		return (0);
	end = getfinalsize(s1, set, &start);
	if (end == -1)
		end = ft_strlen(s1);
	if (!(out = malloc(sizeof(char) * (end - start + 1))))
		return (0);
	cp = out;
	while (start < end)
		*(out++) = s1[start++];
	*out = 0;
	return (cp);
}
