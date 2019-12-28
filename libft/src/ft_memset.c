/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:41:43 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 08:18:09 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *in, int value, size_t count)
{
	unsigned long	i;
	unsigned char	*ptr;

	i = 0;
	ptr = in;
	while (i++ < count)
		*ptr++ = value;
	return (in);
}
