/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:48:53 by edal--ce          #+#    #+#             */
/*   Updated: 2019/11/13 21:34:58 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	char	*cp;
	int		sz;

	int i;
	int j;
	
	i = 0;
	j = 0;
	sz = 1;
	//printf("ici2 |%c|\n",s1[0]);
	//printf("ici |%c|\n",s2[0]);
	if (s1)
		sz += ft_strlen(s1);
	if (s2)
		sz += ft_strlen(s2);
	if (!s1 && !s2)
		return (0);
	//printf("sz = %d\n",sz );

	//printf("ici\n");
	if (!(out = malloc(sizeof(char) * sz)))
		return (0);
	cp = out;
	if (s1)
		while (s1[i] != '\0')
		{
			out[i + j] = s1[i];
			i++;
			//printf("|%c|\n",s1[i] );
			//if(*s1 == 0)
			//	printf("ici2 |%c|\n",*s1);
		}
	if (s2)
		while (s2[j] != '\0')
		{
			out[i + j] = s2[j];
			j++;
		}
		//if(s2[j] == '\0' || s1[i] == '\0')
		//	printf("here |%c| |%c|\n", s1[i], s2[j]);
	out[i + j] = '\0';
	return (cp);
}
