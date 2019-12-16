/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:17:08 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/09 12:17:11 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_rec(unsigned long a, char *bs, char *dt, unsigned long *p)
{
	unsigned long bnb;

	bnb = ft_strlen(bs);
	if (a >= bnb)
		ft_putnbr_base_rec(a / bnb, bs, dt, p);
	ft_addto(dt, p, bs[a % bnb]);
}

void	ft_putnbr_base(unsigned long nbr, char *base, char *dt, unsigned long *nb)
{
	ft_putnbr_base_rec(nbr, base, dt, nb);
	ft_addto(dt, nb, '\0');
}

int		size_int_base(unsigned long nb, unsigned long base_size)
{
	int res;

	res = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base_size;
		res++;
	}
	
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*dest;
	unsigned long		cache;
	unsigned long		nb;
	int		tmp;

	dest = 0;
	if (!ft_base_is_valid(base_to) || !ft_base_is_valid(base_from))
		return (NULL);
	nb = 0;
	if (!nbr[0])
		return (ft_strdup("0"));
	free(dest);
	cache = ft_atoi_base(nbr, base_from);
	tmp = size_int_base(cache, ft_strlen(base_to));
	if (!(dest = malloc(sizeof(char) * tmp + 1)))
		return (0);
	ft_putnbr_base(cache, base_to, dest, &nb);
	return (dest);
}
