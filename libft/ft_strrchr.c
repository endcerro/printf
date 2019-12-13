/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:11:09 by edal--ce          #+#    #+#             */
/*   Updated: 2019/11/04 15:11:10 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *pos;
	char tst;

	tst = c;
	pos = 0;
	while (*str)
	{
		if (*str == c)
			pos = (char *)str;
		str++;
	}
	if (c == *str)
		return ((char *)str);
	return (pos);
}
