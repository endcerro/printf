/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:29:44 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 08:16:54 by edal--ce         ###   ########.fr       */
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
