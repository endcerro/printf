/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 11:39:18 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/16 11:39:19 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*append_char(char *base, char to_add, int count, int order)
{
	int		i;
	char	*out;
	char	*filler;

	i = -1;
	count -= (int)ft_strlen(base);
	if (!(filler = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	while (++i < count)
		filler[i] = to_add;
	filler[i] = '\0';
	if (order == 1)
		out = ft_strjoin(filler, base);
	else
		out = ft_strjoin(base, filler);
	free(base);
	free(filler);
	return (out);
}

char	*process_0(c_contr *controller)
{
	int		i;
	char	*output;
	char	out;
	int		nb;

	out = '0';
	i = 0;
	*(controller->pos) += 1;
	nb = ft_atoi(controller->str_in + *(controller->pos));
	while (ft_isdigit(controller->str_in[*(controller->pos) + i]))
		i++;
	if (controller->str_in[*(controller->pos)] == '*' && ++i)
		nb = va_arg(*(controller->args), int);
	if (controller->str_in[*(controller->pos) + i] == '.')
		out = ' ';
	*(controller->pos) += i;
	i = *(controller->pos);
	output = process_flag(controller);
	if (nb == 0)
		return (output);
	if (controller->str_in[i] == 'i' || controller->str_in[i] == 'd')
		sub_process0(nb, output, out);
	else if ((int)ft_strlen(output) < nb)
		output = append_char(output, out, nb, 1);
	return (output);
}

char	*process_minus(c_contr *controller)
{
	int		i;
	char	*output;
	int		nb;

	i = 0;
	*(controller->pos) += 1;
	output = NULL;
	nb = ft_atoi(controller->str_in + *(controller->pos));
	if (controller->str_in[*(controller->pos)] == '*' && ++i)
		nb = ft_abs(va_arg(*(controller->args), int));
	while (ft_isdigit(controller->str_in[*(controller->pos) + i]))
		i++;
	*(controller->pos) += i;
	output = process_flag(controller);
	if ((int)ft_strlen(output) < nb)
		output = append_char(output, ' ', nb, 0);
	return (output);
}

char	*process_dot(c_contr *controller)
{
	int		i;
	char	*output;
	char	*zeros;
	int		cpt;
	int		nb;
	char	*tmp;

	i = 0;
	*(controller->pos) += 1;
	nb = ft_atoi(controller->str_in + *(controller->pos));
	while (ft_isdigit(controller->str_in[*(controller->pos) + i++]))
		i++;
	if (controller->str_in[*(controller->pos)] == '*' && ++i)
		nb = va_arg(*(controller->args), int);
	*(controller->pos) += i;
	output = process_type(controller);
	if (output == NULL || (output != NULL && output[0] == '%'))
		return (output);
	if (controller->str_in[*(controller->pos) - 1] == 's' && nb >= 0 && i >= 1)
	{
		tmp = ft_substr(output, 0, nb);
		free(output);
		output = tmp;
	}
	else if ((int)ft_strlen(output) <= nb)
	{
		i = -1;
		zeros = malloc(sizeof(char) * (nb - (int)ft_strlen(output) + 1));
		cpt = nb - (int)ft_strlen(output);
		while (++i < cpt)
			zeros[i] = '0';
		zeros[i] = 0;
		if (*output == '-')
		{
			tmp = ft_strjoin(zeros, output + 1);
			free(output);
			output = ft_strjoin("-0", tmp);
			free(tmp);
		}
		else
		{
			tmp = ft_strjoin(zeros, output);
			free(output);
			output = tmp;
		}
		free(zeros);
	}
	if (nb == 0 && output[0] == '0')
		return (ft_strdup(""));
	return (output);
}

char	*process_nb(c_contr *controller)
{
	int		i;
	char	*output;
	int		cpt;
	int		nb;

	i = 0;
	output = NULL;
	nb = ft_atoi(controller->str_in + *(controller->pos));
	while (ft_isdigit(controller->str_in[*(controller->pos) + i]))
		i++;
	if (controller->str_in[*(controller->pos) + i] == '*' && ++i)
		nb = va_arg(*(controller->args), int);
	*(controller->pos) += i;
	output = process_flag(controller);
	cpt = ft_abs(nb) - (int)ft_strlen(output);
	if (cpt > 0 && nb > 0)
		output = append_char(output, ' ', ft_abs(nb), 1);
	else if (cpt > 0)
		output = append_char(output, ' ', ft_abs(nb), 0);
	return (output);
}
