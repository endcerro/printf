/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 03:36:31 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 08:17:11 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		isin(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}

char	*add_fill(char *base, char fill, int cpt, int order)
{
	char	*to_add;
	int		i;
	char	*tmp;

	i = 0;
	if (cpt <= 0)
		return (base);
	if (!(to_add = malloc(sizeof(char) * (cpt + 1))))
		return (NULL);
	while (i < cpt)
		to_add[i++] = fill;
	to_add[i] = '\0';
	if (order == 1)
		tmp = ft_strjoin(to_add, base);
	else
		tmp = ft_strjoin(base, to_add);
	free(base);
	free(to_add);
	return (tmp);
}

char	*add_fill_0(char *base, char fill, int cpt, int order)
{
	char *out;

	base[0] = '0';
	out = add_fill(base, fill, cpt, order);
	out[0] = '-';
	return (out);
}

char	*add_fill_hex(char *base, char fill, int cpt, int order)
{
	char *out;

	base[1] = '0';
	out = add_fill(base, fill, cpt, order);
	out[1] = 'x';
	return (out);
}

int		refresh(t_contr *controller, int pos, int j, int p)
{
	controller->flags->vals[p] = ft_atoi(controller->str_in + j + pos);
	while (isin(controller->str_in[j + pos], "0123456789") &&
		controller->str_in[j + pos] != '\0')
		pos++;
	return (pos);
}
