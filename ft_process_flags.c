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

unsigned char	*append_char(unsigned char *base, char to_add, int count, int order)
{
	int		i;
	unsigned char	*out;
	unsigned char	*filler;

	i = -1;
	count -= (int)ft_ustrlen(base);
	if (!(filler = malloc(sizeof(unsigned char) * (ft_abs(count) + 1))))
		return (NULL);
	while (++i < count)
		filler[i] = to_add;
	filler[i] = '\0';
	if (order == 1)
		out = ft_ustrjoin(filler, base);
	else
		out = ft_ustrjoin(base, filler);
	free(base);
	free(filler);
	//base = NULL;
	//filler = NULL;
	return (out);
}

unsigned char	*process_0(c_contr *controller)
{
	int		i;
	unsigned char	*output;
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
	//printf("out = %d\n", out);
	*(controller->pos) += i;
	i = *(controller->pos);
	//printf("b4 proccess\n");
	output = process_flag(controller);
	//printf("AF proccess\n");
	//printf("POS 1, i = |%c| \n", controller->str_in[i]);
	if (nb == 0)
		return (output);
	//printf("POS 2, %s \n", output);
	if (controller->str_in[i] == 'i' || controller->str_in[i] == 'd')
	{

		//printf("POS 3\n");
		//printf("c = %s\n", output);
		sub_process0(nb, &output, out);
		//printf("|%s|\n",output );

	}	
	else if ((int)ft_ustrlen(output) < nb + 1)
	{
		//printf("POS 4\n");
		output = append_char(output, out, nb, 1);
	}
	//printf("ENDPOS \n");
	return (output);
}

unsigned char	*process_minus(c_contr *controller)
{
	int		i;
	unsigned char	*output;
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
	if ((int)ft_ustrlen(output) < nb)
		output = append_char(output, ' ', nb, 0);
	return (output);
}

unsigned char	*process_dot(c_contr *controller)
{
	int		i;
	unsigned char	*output;
	unsigned char	*zeros;
	int		cpt;
	int		nb;
	unsigned char	*tmp;

	i = 0;
	*(controller->pos) += 1;
	nb = ft_atoi(controller->str_in + *(controller->pos));
	while (ft_isdigit(controller->str_in[*(controller->pos) + i]))
		i++;
	if (controller->str_in[*(controller->pos)] == '*' && ++i)
		nb = va_arg(*(controller->args), int);
	//printf("i = %d ?\n",i);
	*(controller->pos) += i;
	output = process_type(controller);
	
	if (output == NULL)
	{	
	//	printf("la\n");
		return (NULL);
	}
	//printf("la\n");
	if(output != NULL && output[0] == '%')
		return (output);
	//printf("la\n");
	if (controller->str_in[*(controller->pos) - 1] == 's' && nb >= 0 && i >= 1)
	{
		tmp = ft_usubstr(output, 0, nb);
		free(output);
		output = tmp;
	}
	else if ((int)ft_ustrlen(output) <= nb)
	{
		i = -1;
		if(!(zeros = malloc(sizeof(unsigned char) * (nb - (int)ft_ustrlen(output) + 1))))
			return 0;
		cpt = nb - (int)ft_ustrlen(output);
		while (++i < cpt)
			zeros[i] = '0';
		zeros[i] = 0;
		if (*output == '-')
		{
			tmp = ft_ustrjoin(zeros, output + 1);
			free(output);
			output = ft_ustrjoin((unsigned char *)"-0", tmp);
			free(tmp);
		}
		else
		{
			tmp = ft_ustrjoin(zeros, output);
			free(output);
			output = tmp;
		}
		free(zeros);
	}
	if (nb == 0 && output[0] == '0')
		return (ft_ustrdup((unsigned char *)""));
	return (output);
}

unsigned char	*process_nb(c_contr *controller)
{
	int		i;
	unsigned char	*output;
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
	cpt = ft_abs(nb) - (int)ft_ustrlen(output);
	if (cpt > 0 && nb > 0)
		output = append_char(output, ' ', ft_abs(nb), 1);
	else if (cpt > 0)
		output = append_char(output, ' ', ft_abs(nb), 0);
	return (output);
}
