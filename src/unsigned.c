/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:27:15 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/18 18:27:17 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putustr(unsigned char *in)
{
	int i;

	i = 0;
	while (in[i] != '\0')
	{
		if (in[i] == 160)
			write(1, "\0", 1);
		else
			write(1, in + i, 1);
		i++;
	}
}

int				ft_ustrlen(unsigned char *str)
{
	int i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned char	*ft_ustrdup(unsigned char *s1)
{
	int				i;
	unsigned char	*p;

	if (s1 == NULL)
		return (NULL);
	if (!(p = malloc(sizeof(unsigned char) * (ft_ustrlen(s1) + 1))))
		return (0);
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	p[i] = '\0';
	return (p);
}

unsigned char	*ft_ustrjoin(unsigned char *s1, unsigned char *s2)
{
	unsigned char	*out;
	int				sz;
	int				i;
	int				j;

	i = -1;
	j = 0;
	sz = 1;
	if (s1 != NULL)
		sz += ft_ustrlen((unsigned char*)s1);
	if (s2 != NULL)
		sz += ft_ustrlen((unsigned char*)s2);
	if (!s1 && !s2)
		return (0);
	if (!(out = malloc(sizeof(unsigned char) * sz)))
		return (0);
	if (s1)
		while (s1[++i] != '\0')
			out[i] = s1[i];
	if (s2)
		while (s2[j] != '\0')
			out[i++] = s2[j++];
	out[i] = '\0';
	return (out);
}

unsigned char	*ft_usubstr(unsigned char *s, unsigned int start, size_t len)
{
	unsigned char	*out;
	unsigned char	*cp;
	size_t			i;

	i = 0;
	out = 0;
	if (!s)
		return (0);
	if ((ft_ustrlen(s) < (int)start || len == 0))
		return (ft_ustrdup((unsigned char*)""));
	if (!(out = malloc(sizeof(unsigned char) * (len + 1))))
		return (0);
	cp = out;
	while (s[start + i] && i < len)
		*(out++) = s[start + i++];
	*out = 0;
	return (cp);
}
