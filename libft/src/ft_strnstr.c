/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:19:59 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 08:18:27 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *lookin, const char *tolook, size_t n)
{
	size_t	i;
	size_t	j;
	char	*out;

	j = 0;
	i = 0;
	if (tolook[0] == 0 || !tolook)
		return ((char *)lookin);
	while (i < n && lookin[i])
	{
		if (lookin[i] == tolook[j])
		{
			if (j == 0)
				out = (char *)&lookin[i];
			if (tolook[++j] == 0)
				return (out);
		}
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	return (0);
}
