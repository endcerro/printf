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

unsigned char	*append_char(unsigned char *base, char t_a, int cpt, int order)
{
	int				i;
	unsigned char	*out;
	unsigned char	*filler;

	i = -1;
	cpt -= (int)ft_ustrlen(base);
	if (!(filler = malloc(sizeof(unsigned char) * (ft_abs(cpt) + 1))))
		return (NULL);
	while (++i < cpt)
		filler[i] = t_a;
	filler[i] = '\0';
	if (order == 1)
		out = ft_ustrjoin(filler, base);
	else
		out = ft_ustrjoin(base, filler);
	free(base);
	free(filler);
	return (out);
}

unsigned char	*process_0(t_contr *controller)
{
	unsigned char	*output;
	int				i;
	char			out;
	int				nb;

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
		sub_process0(nb, &output, out);
	else if ((int)ft_ustrlen(output) < nb + 1)
		output = append_char(output, out, nb, 1);
	return (output);
}

unsigned char	*process_minus(t_contr *controller)
{
	unsigned char	*output;
	int				i;
	int				nb;

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
	if ((int)ft_ustrlen(output) < nb)
		output = append_char(output, ' ', nb, 0);
	return (output);
}

unsigned char	*process_dot(t_contr *controller)
{
	int				i;
	unsigned char	*output;
	int				nb;
	unsigned char	*tmp;

	i = 0;
	*(controller->pos) += 1;
	nb = ft_atoi(controller->str_in + *(controller->pos));
	//printf("i = %d\n",i );
	while (ft_isdigit(controller->str_in[*(controller->pos) + i]))
		i++;
	if (controller->str_in[*(controller->pos)] == '*' && ++i)
		nb = va_arg(*(controller->args), int);
	*(controller->pos) += i;
	output = process_type(controller);
	//printf("char = %c, nb = %d, i = %d\n",controller->str_in[*(controller->pos) - 1],nb, i  );
	//printf("%s\n",output );
	if (output == NULL)
		return (NULL);
	//printf("%s\n",output );
	if (output[0] == '%')
		return (output);
	//printf("char = %c, nb = %d, i = %d\n",controller->str_in[*(controller->pos) - 1],nb, i  );
	//printf("%s\n",output );
	if (controller->str_in[*(controller->pos) - 1] == 's' && nb >= 0 && i >= 1)
	{
		//printf("here\n");
		tmp = ft_usubstr(output, 0, nb);
	}
	else
	{
		//printf("%s\n",output );
		return (sub_process_dot(output, nb));
	
	}
	free(output);
	output = tmp;
	//printf("%s\n",output );
	return (output);
}

unsigned char	*process_nb(t_contr *controller)
{
	int				i;
	unsigned char	*output;
	int				cpt;
	int				nb;

	i = 0;
	output = NULL;
	nb = ft_atoi(controller->str_in + *(controller->pos));
	while (ft_isdigit(controller->str_in[*(controller->pos) + i]))
		i++;
	if (controller->str_in[*(controller->pos) + i] == '*' && ++i)
		nb = va_arg(*(controller->args), int);
	*(controller->pos) += i;
	output = process_flag(controller);
	cpt = ft_abs(nb) - (int)ft_ustrlen(output);
	if (cpt > 0 && nb > 0)
		output = append_char(output, ' ', ft_abs(nb), 1);
	else if (cpt > 0)
		output = append_char(output, ' ', ft_abs(nb), 0);
	return (output);
}
