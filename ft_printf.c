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
	char *output;
	char *temp;
	char c;
	output = 0;

	c = controller->str_in[*(controller->pos)]; 
	if(c == 'd' || c == 'i')
	{
		output =  ft_itoa(va_arg(*(controller->args), int));
	}
	else if(c == 'u')
	{
		output = ft_ultoa(va_arg(*(controller->args), unsigned int));
	}
	else if(c == 'c')
	{
		output = malloc(sizeof(char) * 2);
		*output = va_arg(*(controller->args), int);
		output[1] = 0;
	}
	else if(c == '%')
	{
		output = malloc(sizeof(char) * 2);
		*output = '%';
		output[1] = 0;
	}
	else if(c == 's')
	{
		char *test = va_arg(*(controller->args), char*);
		if(test != NULL)
			output = ft_strdup((const char*)test);
	}
	else if(c == 'p')
	{
		unsigned long ul = va_arg(*(controller->args), unsigned long);
		temp = ft_convert_base(ft_ultoa(ul),"0123456789", "0123456789abcdef");
		output = ft_strjoin("0x", temp);
		free(temp);
	}
	else if(c == 'x')
	{
		temp = ft_ultoa((unsigned long)va_arg(*(controller->args), unsigned int));
		output = ft_convert_base(temp, "0123456789", "0123456789abcdef");
		free(temp);
	}
	else if(c == 'X')
	{	
		temp = ft_ultoa((unsigned long)va_arg(*(controller->args), unsigned int));
		output = ft_convert_base(temp,"0123456789", "0123456789ABCDEF");
		free(temp);
	}
	//Pas sur du &&
	if(output == NULL && c == 's')
		*(controller->len) += 1;
	*(controller->pos) += 1;
	return output;
}

char *process_flag(c_contr *controller)
{
	char c = (controller->str_in)[*(controller->pos)];
	char *out;

	if (c == '0')
		out = process_0(controller);
	else if (c == '-')
		out = process_minus(controller);
	else if (isnumber(c))
		out = process_nb(controller);
	else if (c == '.')
		out = process_dot(controller);
	else if (c == '*')
		out = process_nb(controller);
	else
		out = process_type(controller);
	return (out);
}

char *process(c_contr *controller)
{
	char *output;
	char c_to_s[2];
	char *tmp;
	char *tmp2;


	tmp = 0;
	c_to_s[0] = '\0';
	c_to_s[1] = '\0';
	output = NULL;
	if((controller->str_in)[*(controller->pos)] == 0)
		return (ft_strdup(c_to_s));
	
	if((controller->str_in)[*(controller->pos)] == '%')
	{		
		*(controller->pos) += 1;//
		tmp = process_flag(controller);
		tmp2 = process(controller);//
		output = ft_strjoin(tmp, tmp2);
		//free(tmp);
		free(tmp2);
	}
	else if((controller->str_in)[*(controller->pos)] != 0)
	{
		c_to_s[0] = (controller->str_in)[*(controller->pos)];
		*(controller->pos) += 1;//
		tmp = process(controller);//
		output = ft_strjoin(c_to_s, tmp);
		//free(tmp);
	}
	free(tmp);
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
   	free(to_print);
   	*(controller->len) += ft_strlen(to_print); 
   	return *(controller->len);
}
