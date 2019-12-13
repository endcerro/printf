/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:45:03 by edal--ce          #+#    #+#             */
/*   Updated: 2019/11/07 15:45:04 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *str, char sep)
{
	int cpt;
	int i;
	int reading;

	reading = 0;
	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] == sep)
		{
			if (reading)
				cpt++;
			reading = 0;
		}
		else
			reading = 1;
		i++;
	}
	if (reading)
		cpt++;
	return (cpt);
}

static char	*cpy(char *str, char sep)
{
	char	*out;
	int		i;

	i = 0;
	while (str[i] != sep && str[i])
		i++;
	if (!(out = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] != sep && str[i])
	{
		out[i] = str[i];
		i++;
	}
	out[i] = 0;
	return (out);
}

static char	**clearsplit(char **in, int cpt)
{
	int i;

	i = 0;
	while (i < cpt)
	{
		free(in[i]);
		in[i] = 0;
		i++;
	}
	free(in);
	return (0);
}

char		**ft_split(char const *str, char sep)
{
	char	**out;
	int		cpt;
	int		nbout;
	char	*tmp;

	if (!str)
		return (0);
	tmp = (char *)str;
	cpt = 0;
	nbout = countwords(str, sep);
	if (!(out = malloc(sizeof(char *) * (nbout + 1))))
		return (0);
	while (*tmp == sep && *tmp)
		tmp++;
	while (cpt < nbout && *tmp)
	{
		while (*tmp == sep && *tmp)
			tmp++;
		out[cpt++] = cpy(tmp, sep);
		if (out[cpt - 1] == 0)
			return (clearsplit(out, cpt - 1));
		tmp += ft_strlen(out[cpt - 1]);
	}
	out[cpt] = 0;
	return (out);
}
