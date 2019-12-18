/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:29:44 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/18 18:29:45 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long		getlen(unsigned long n)
{
	unsigned long i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static unsigned long		ft_powu(unsigned long nb, unsigned long pow)
{
	unsigned long i;
	unsigned long dest;

	dest = 1;
	i = 0;
	while (++i < pow)
		dest = dest * nb;
	return (dest);
}

char						*ft_ultoa(unsigned long n)
{
	char				*out;
	unsigned long		len;
	unsigned long		i;
	unsigned long		indxo;

	indxo = 0;
	i = 0;
	len = getlen(n);
	if (!(out = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		out[indxo++] = (n / ft_powu(10, len - i)) + '0';
		n -= n / ft_powu(10, len - i) * ft_powu(10, len - i);
		i++;
	}
	out[indxo] = '\0';
	return (out);
}

unsigned char				*sub_process_dot(unsigned char *output, int nb)
{
	int				i;
	unsigned char	*zeros;

	if ((int)ft_ustrlen(output) <= nb)
	{
		i = -1;
		if (!(zeros = malloc(sizeof(unsigned char) *
			(nb - (int)ft_ustrlen(output) + 1))))
			return (0);
		while (++i < (nb - (int)ft_ustrlen(output)))
			zeros[i] = '0';
		zeros[i] = 0;
		output = sub_sub_dot(output, zeros);
	}
	if (nb == 0 && output[0] == '0')
	{
		free(output);
		output = ft_ustrdup((unsigned char *)"");
	}
	return (output);
}
