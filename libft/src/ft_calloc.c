/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:33:14 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 08:17:22 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t s)
{
	char				*mem;
	unsigned long		i;

	i = 0;
	if (!(mem = malloc(n * s)))
		return (0);
	while (i < (n * s))
		mem[i++] = 0;
	return (mem);
}
