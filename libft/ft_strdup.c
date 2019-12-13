/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:28:14 by edal--ce          #+#    #+#             */
/*   Updated: 2019/09/09 13:28:17 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	printf("NNULL\n");
	int		i;
	char	*p;
	if(s1 == NULL)
	{
		printf("NNULL\n");
		return NULL;
	}
	printf("NNULL\n");
	if (!(p = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	p[i] = 0;
	return (p);
}
