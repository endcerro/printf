/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:11:09 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 08:18:28 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *pos;

	pos = NULL;
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
