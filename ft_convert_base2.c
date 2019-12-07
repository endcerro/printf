/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:17:20 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/09 12:17:21 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addto(char *st, unsigned long *nb, char c)
{
	st[*nb] = c;
	*nb = *nb + 1;
}

int		mchb_strl(char nb, char *base)
{
	unsigned long j;

	j = 0;
		while (base[j] && base[j] != nb)
			j++;
		if (!base[j])
			return (-1);
		return (j);
}

unsigned long		ft_base_is_valid(char *base)
{
	unsigned long i;
	unsigned long j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		j = 0;
		if (base[i] == 43 || base[i] == 45 || base[i] == 32
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		while (base[j])
		{
			if (base[j] == base[i] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

unsigned long		clean(char *nb, char *base, char *dest)
{
	unsigned long nbminus;
	unsigned long i;
	unsigned long j;

	i = 0;
	nbminus = 0;
	j = 0;
	while (mchb_strl(nb[i], base) > -1 && nb[i])
	{
		dest[j] = nb[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (nbminus);
}

unsigned long		ft_atoi_base(char *nb, char *base)
{
	unsigned long		i;
	unsigned long		final_nb;
	unsigned long		retnb;
	char				cpy[ft_strlen(nb)];
	unsigned long		size;

	i = 0;
	final_nb = 0;
	retnb = clean(nb, base, cpy);
	//printf("retnb = %lu\n",retnb);
	size = ft_strlen(cpy);
	while (cpy[i])
	{
		final_nb = final_nb * ft_strlen(base) + mchb_strl((cpy[i]), base);
		i++;
	}
	return (final_nb);
}
