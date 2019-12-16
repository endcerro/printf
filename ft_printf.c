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
#include "libft.h"
#include <stdarg.h>

char *process_type(c_contr *controller)
{
	char *output;
	char *temp;
	char c;

	output = NULL;

	c = controller->str_in[*(controller->pos)];
	if(c == 'd' || c == 'i')
		output =  ft_itoa(va_arg(*(controller->args), int));
	else if(c == 'u')
		output = ft_ultoa(va_arg(*(controller->args), unsigned int));
	else if(c == '%' || c == 'c')
	{
		if(!(output = malloc(sizeof(char) * 2)))
			return (NULL);
		output[0] = '%';
		output[1] = '\0';
		if(c == 'c')
		{
			output[0] = va_arg(*(controller->args), int);
			if (output[0] == 0)
			{	
				free(output);
				output = NULL;
			}
		}
	}
	else if(c == 's')
	{
		temp = va_arg(*(controller->args), char*);
		if(temp != NULL)
		{
			output = ft_strdup(temp);
			//printf("%s\n",output );
			//free(temp);
		}
		else
			output = ft_strdup("(null)");
		//free(temp);
	}
	else if(c == 'p')
	{
		temp = ft_convert_base(ft_ultoa(va_arg(*(controller->args), unsigned long)), "0123456789", "0123456789abcdef");
		output = ft_strjoin("0x", temp);
		free(temp);
	}
	else if(c == 'X' || c == 'x')
	{	
		temp = ft_ultoa((unsigned long)va_arg(*(controller->args), unsigned int));
		if(c == 'x'){
			output = ft_convert_base(temp, "0123456789", "0123456789abcdef");
			free(temp);
		}
		else{
			output = ft_convert_base(temp, "0123456789", "0123456789ABCDEF");
			free(temp);
		}
		
	}
	//Pas sur du &&
	if(output == NULL)
		*(controller->len) += 1;
	*(controller->pos) += 1;
	return (output);
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
	char *tmp[2];

	if ((controller->str_in)[*(controller->pos)] == '\0')
		return (ft_strdup(""));
	c_to_s[1] = '\0';
	output = NULL;
	*(controller->pos) += 1;
	if ((controller->str_in)[*(controller->pos)] == '\0')
	{
		//printf("BS ZERO\n");
		//	return NULL;	
	}

	if ((controller->str_in)[*(controller->pos) - 1] == '%')
	{
		if((controller->str_in)[*(controller->pos)] == '\0')
			tmp[0] = NULL;
		else
			tmp[0] = process_flag(controller);
	}
	else if ((tmp[0] = &(c_to_s[0])))
		c_to_s[0] = (controller->str_in)[*(controller->pos) - 1];
	tmp[1] = process(controller);
	output = ft_strjoin(tmp[0], tmp[1]);
	if(tmp[0] != &(c_to_s[0]))
	{
		//printf("wefree\n");
		free(tmp[0]);
	}
	//free(tmp[0]);
	free(tmp[1]);
	return (output);
}

int ft_printf(const char *str_in, ...)
{
	struct c_list 	*controller;
	char 			*to_print;
	int 			vars[2];
	va_list 		args;
	
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
   	ft_putstr(to_print);
   	vars[0] += ft_strlen(to_print);
   	free(to_print);
   	free(controller);
   	va_end(args);
   	return (vars[0]);

}
