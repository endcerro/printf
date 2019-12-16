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
	ft_strlen(base);
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
	//if (!(nb = malloc(sizeof(unsigned long) * 1)))
	//	return (0);
	nb = 0;
	if (!nbr[0])
	{
		if (!(dest = malloc(sizeof(char) * 2)))
			return (0);
		dest[0] = '0';
		dest[1] = '\0';
	//	free(nb);
		printf("this way\n");
		return (dest);
	}
	free(dest);
	//printf("NB B4 %s\n",nbr);
	cache = ft_atoi_base(nbr, base_from);
	//printf("NB AF %lu\n",cache);
	tmp = size_int_base(cache, ft_strlen(base_to));
	if (!(dest = malloc(sizeof(char) * tmp + 1)))
	{
		printf("this way\n");
	//	free(nb)
		return (0);
	}
	printf("this way\n");
	ft_putnbr_base(cache, base_to, dest, &nb);
	//printf("OUTPUT = %s\n", dest);
	//free(nb);
	return (dest);
	//return 0;
}
