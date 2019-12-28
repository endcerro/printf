/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:28:14 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 08:18:20 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*p;

	if (s1 == NULL)
		return (NULL);
	if (!(p = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	p[i] = 0;
	return (p);
}
