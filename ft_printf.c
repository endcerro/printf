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
#include <stdarg.h>

char *process_type(c_contr *controller)
{

	//GERE FLAGS 0 - * .
	int i;
	char *output;
	char *temp;
	int nb;

	nb = 0;
	i = 0;
	output = 0;

	//printf("processing ;%c\n",controller->str_in[*(controller->pos)]);
	if(controller->str_in[*(controller->pos)] == 'd' || controller->str_in[*(controller->pos)] == 'i')
	{
		output =  ft_itoa(va_arg(*(controller->args), int));

	}
	else if(controller->str_in[*(controller->pos)] == 'u')
	{	
		output =  ft_ultoa(va_arg(*(controller->args), unsigned int));
	}
	else if(controller->str_in[*(controller->pos)] == 'c')
	{
			output = malloc(sizeof(char) * 2);
			*output = va_arg(*(controller->args), int);
			output[1] = 0;
	}
	else if(controller->str_in[*(controller->pos)] == '%')
	{
		output = malloc(sizeof(char) * 2);
		*output = '%';
		output[1] = 0;
	}
	else if(controller->str_in[*(controller->pos)] == 's' && ++i)
		output = ft_strdup(va_arg(*(controller->args), char*));
	else if(controller->str_in[*(controller->pos)] == 'p' && ++i)
	{
		unsigned long ul = va_arg(*(controller->args), unsigned long);
		temp = ft_convert_base(ft_ultoa(ul),"0123456789", "0123456789abcdef");
		output = ft_strjoin("0x", temp);
		
	}
	else if(controller->str_in[*(controller->pos)] == 'x')
		output = ft_convert_base(ft_ultoa((unsigned long)va_arg(*(controller->args), unsigned int)),"0123456789", "0123456789abcdef");
	else if(controller->str_in[*(controller->pos)] == 'X')
		output = ft_convert_base(ft_ultoa((unsigned long)va_arg(*(controller->args), unsigned int)),"0123456789", "0123456789ABCDEF");
	//if(output != NULL)
	*(controller->pos) += 1;
	if(output == NULL)
		*(controller->len) += 1;
	return output;
}

char *process_flag(c_contr *controller)
{
	char c = (controller->str_in)[*(controller->pos)];
	char *out;

	//printf(" c = %c\n", c);
	if(c == '0')
		out = process_0(controller);
	else if(c == '-')
		out = process_minus(controller);
	else if(isnumber(c))
		out = process_nb(controller);
	else if(c == '.')
		out = process_dot(controller);
	else if(c == '*')
		out = process_nb(controller);
	else
		out = process_type(controller);
	//printf("%s\n",out);
	return out;
}

char *process(c_contr *controller)
{
	char *output;
	char c_to_s[2];

	c_to_s[1] = '\0';
	output = 0;
	if((controller->str_in)[*(controller->pos)] == 0)
	{
		c_to_s[0] = 0;
		return ft_strdup(c_to_s);
	}
	if((controller->str_in)[*(controller->pos)] == '%')
	{	
			*(controller->pos) += 1;
			output = ft_strjoin(process_flag(controller), process(controller));
			//printf("output = %s",output );
	}
	else if((controller->str_in)[*(controller->pos)] != 0)
	{
		c_to_s[0] = (controller->str_in)[*(controller->pos)];
		*(controller->pos) += 1;
		output = ft_strjoin(c_to_s, process(controller));
	}
	return output;
}

int ft_printf(const char *str_in, ...)
{
	char *to_print;
	int len;
	int pos;

	pos = 0;
	len = 0;
 	va_list args;
 	struct c_list *controller;
 	controller = malloc(sizeof(c_contr));

 	controller->str_in = (char *)str_in;
 	controller->len = &len;
 	controller->args = &args;
 	controller->pos = &pos;

    va_start(args, str_in);
   	
   	to_print = process(controller);
   	printf("%s",to_print );
   	*(controller->len) += ft_strlen(to_print); 
   	return *(controller->len);
}
