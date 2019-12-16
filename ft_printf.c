/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:08:05 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/09 17:08:08 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*process_type(c_contr *controller)
{
	char *output;
	char c;

	output = NULL;
	c = controller->str_in[*(controller->pos)];
	if (c == 'd' || c == 'i')
		output = ft_itoa(va_arg(*(controller->args), int));
	else if (c == 'u')
		output = ft_ultoa(va_arg(*(controller->args), unsigned int));
	else if (c == '%' || c == 'c')
	{
		output = ft_strdup("%");
		if (c == 'c')
		{
			output[0] = va_arg(*(controller->args),unsigned int);
			//if(output[0] = '\0')
				//output[0] = 160;
			//return(output);
			//printf("|%c|\n",output[0]);
			//printf("|%c|\n",0);
		}
	}
	else if (c == 's')
		output = process_s(controller);
	else if (c == 'p')
		output = process_p(controller);
	else if (c == 'X' || c == 'x')
		output = process_x(controller, c);
	//else
	//	*(controller->len) += 1;
	if ( c != 's' && output[0] == '\0')
	{
		//printf("here\n");
		*(controller->len) += 1;
	}
	*(controller->pos) += 1;
	//printf("|%c|\n",output[0]);
	return (output);
}

char	*process_flag(c_contr *controller)
{
	char c;

	c = (controller->str_in)[*(controller->pos)];
	//*(controller->len) += 1;
	if (c == '0')
		return (process_0(controller));
	else if (c == '-')
		return (process_minus(controller));
	else if (ft_isdigit(c))
		return (process_nb(controller));
	else if (c == '.')
		return (process_dot(controller));
	else if (c == '*')
		return (process_nb(controller));
	else
	{
		char *output =process_type(controller);
		//printf("|%c|\n",output[0]);
		return (output);
	}
}

char	*process(c_contr *controller)
{
	char *output;
	char c_to_s[2];
	char *tmp[2];

	if ((controller->str_in)[*(controller->pos)] == '\0')
		return (ft_strdup(""));
	c_to_s[1] = '\0';
	output = NULL;
	*(controller->pos) += 1;
	if ((controller->str_in)[*(controller->pos) - 1] == '%')
	{
		tmp[0] = NULL;
		if ((controller->str_in)[*(controller->pos)] != '\0')
			tmp[0] = process_flag(controller);
		//printf("|%c|\n",tmp[0][0]);
	}
	else if ((tmp[0] = &(c_to_s[0])))
		c_to_s[0] = (controller->str_in)[*(controller->pos) - 1];
	tmp[1] = process(controller);
	output = ft_strjoin(tmp[0], tmp[1]);
	if (tmp[0] != &(c_to_s[0]))
		free(tmp[0]);
	free(tmp[1]);
	
	return (output);
}

int		ft_printf(const char *str_in, ...)
{
	struct c_list	*controller;
	char			*to_print;
	int				vars[2];
	va_list			args;

	if (!(controller = malloc(sizeof(c_contr))))
		return (0);
	va_start(args, str_in);
	vars[0] = 0;
	vars[1] = 0;
	controller->str_in = (char *)str_in;
	controller->args = &args;
	controller->len = &(vars[0]);
	controller->pos = &(vars[1]);
	to_print = process(controller);
	ft_putstr_fd((unsigned char*)to_print, 1);
	if(to_print[0] == '\0')
	{
		//vars[0] +=
		//printf("here");
	}
	vars[0] += ft_strlen(to_print);
	free(to_print);
	free(controller);
	va_end(args);
	return (vars[0]);
}
