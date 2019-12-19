/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:08:05 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/18 21:50:51 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*sub_switch(t_contr *controller, char c)
{
	unsigned char *output;

	output = ft_ustrdup((unsigned char*)"%");
	if (c == 'c')
	{
		output[0] = va_arg(*(controller->args), int);
		if (output[0] == 0)
			output[0] = 160;
	}
	return (output);
}

unsigned char	*process_type(t_contr *controller)
{
	unsigned char	*output;
	char			c;

	output = NULL;
	c = controller->str_in[*(controller->pos)];
	if (c == 'd' || c == 'i')
		output = ft_itoua(va_arg(*(controller->args), int));
	else if (c == 'u')
		output = (unsigned char*)ft_ultoa(va_arg(*(controller->args),
		unsigned int));
	else if (c == '%' || c == 'c')
		output = sub_switch(controller, c);
	else if (c == 's')
		output = process_s(controller);
	else if (c == 'p')
		output = process_p(controller);
	else if (c == 'X' || c == 'x')
		output = process_x(controller, c);
	if (c != 's' && output != NULL && output[0] == '\0')
		*(controller->len) += 1;
	*(controller->pos) += 1;
	//printf("output = %s\n",output );
	return (output);
}

unsigned char	*process_flag(t_contr *controller)
{
	char c;

	c = (controller->str_in)[*(controller->pos)];
	if (c == '0')
		return (process_0(controller));
	else if (c == '-')
		return (process_minus(controller));
	else if (ft_isdigit(c))
		return (process_nb(controller));
	else if (c == '.')
	{
			//printf("here\n");
		return (process_dot(controller));
	}
	else if (c == '*')
		return (process_nb(controller));
	else if (c == '\0')
		return (NULL);
	else
		return (process_type(controller));
}

unsigned char	*process(t_contr *controller)
{
	unsigned char *output;
	unsigned char c_to_s[2];
	unsigned char *tmp[2];

	if ((controller->str_in)[*(controller->pos)] == '\0')
		return (ft_ustrdup((unsigned char *)""));
	c_to_s[1] = '\0';
	output = NULL;
	*(controller->pos) += 1;
	if ((controller->str_in)[*(controller->pos) - 1] == '%')
	{
		//printf("FLAG\n");
		tmp[0] = NULL;
		if ((controller->str_in)[*(controller->pos)] != '\0')
			tmp[0] = process_flag(controller);
	}
	else if ((tmp[0] = &(c_to_s[0])))
		c_to_s[0] = (controller->str_in)[*(controller->pos) - 1];
	tmp[1] = process(controller);
	output = ft_ustrjoin(tmp[0], tmp[1]);
	if (tmp[0] != &(c_to_s[0]) && tmp[0] != NULL)
		free(tmp[0]);
	free(tmp[1]);
	return (output);
}

int				ft_printf(const char *str_in, ...)
{
	struct s_contr	*controller;
	unsigned char	*to_print;
	int				vars[2];
	va_list			args;

	if (!(controller = malloc(sizeof(t_contr))))
		return (0);
	va_start(args, str_in);
	vars[0] = 0;
	vars[1] = 0;
	controller->str_in = (char *)str_in;
	controller->args = &args;
	controller->len = &(vars[0]);
	controller->pos = &(vars[1]);
	to_print = process(controller);
	ft_putustr(to_print);
	vars[0] += ft_ustrlen(to_print);
	free(to_print);
	free(controller);
	va_end(args);
	return (vars[0]);
}
