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

unsigned char	*process_type(c_contr *controller)
{
	unsigned char *output;
	char c;


	
	output = NULL;
//	printf("Alive\n");
//	printf("pos = %d\n",*(controller->pos));
//	printf("pos = %s\n",controller->str_in);
//	printf("pos = %c\n",controller->str_in[*(controller->pos)]);

	c = controller->str_in[*(controller->pos)];
	//printf("here\n");	
	if (c == 'd' || c == 'i')
	{
		//printf("here\n");
		output = (unsigned char*)ft_itoa(va_arg(*(controller->args), int));
	}
	else if (c == 'u')
		output = (unsigned char*)ft_ultoa(va_arg(*(controller->args), unsigned int));
	else if (c == '%' || c == 'c')
	{
		output = ft_ustrdup((unsigned char*)"%");
		if (c == 'c')
		{
			output[0] = va_arg(*(controller->args), int);
			if(output[0] == 0)
			{
				output[0] = 160;	
				//printf("case\n");
			}
		}
		
	}
	else if (c == 's')
		output = process_s(controller);
	else if (c == 'p')
		output = process_p(controller);
	else if (c == 'X' || c == 'x')
		output = process_x(controller, c);
	//printf("end\n");
	//else
	//	*(controller->len) += 1;
	if ( c != 's' && output != NULL && output[0] == '\0')
	{
		//printf("here\n");
		*(controller->len) += 1;
	}
	//printf("Alive ! \n");
	*(controller->pos) += 1;
	//printf("ici\n");
	return (output);
}

unsigned char	*process_flag(c_contr *controller)
{
	char c;
	//printf("process_flag\n");
	//printf("ici\n");
	c = (controller->str_in)[*(controller->pos)];
	//*(controller->len) += 1;
	if (c == '0')
	{
	//	printf("here e are\n");
		unsigned char *z = process_0(controller); 
	//	printf("we still2\n");
		return (z);
		//return (process_0(controller));
	}
	else if (c == '-')
		return (process_minus(controller));
	else if (ft_isdigit(c))
		return (process_nb(controller));
	else if (c == '.')
	{
		//return (process_dot(controller));
	//	printf("ici2\n");
		unsigned char *z = process_dot(controller); 
	//	printf("ici2\n");
		return (z);
	}
	else if (c == '*')
		return (process_nb(controller));
	else
	{	
	//	printf("ici2\n");
		unsigned char *z = process_type(controller); 
		
		return (z);
	}
}

unsigned char	*process(c_contr *controller)
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
		tmp[0] = NULL;
		if ((controller->str_in)[*(controller->pos)] != '\0')
		{	
	//		printf("OK\n");
			tmp[0] = process_flag(controller);
	//		printf("NOK\n");
		}
	}
	else if ((tmp[0] = &(c_to_s[0])))
	{
		c_to_s[0] = (controller->str_in)[*(controller->pos) - 1];

	}
	tmp[1] = process(controller);
	output = ft_ustrjoin(tmp[0], tmp[1]);
	if (tmp[0] != &(c_to_s[0]))
	{
		//printf("THIs is here\n");
		free(tmp[0]);
	}
	free(tmp[1]);
	
	return (output);
}

int		ft_printf(const char *str_in, ...)
{
	struct c_list	*controller;
	unsigned char	*to_print;
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
	ft_putustr(to_print);
	if(to_print[0] == '\0')
	{
		//vars[0] +=
		//printf("here");
	}
	vars[0] += ft_ustrlen(to_print);
	free(to_print);
	free(controller);
	va_end(args);
	return (vars[0]);
}
