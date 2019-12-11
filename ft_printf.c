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

char *process_type(char *input, int c, va_list args, int *len)
{

	//GERE FLAGS 0 - * .
	int i;
	char *output;
	char *temp;
	int j;
	int nb;
	nb = 0;
	i = 0;
	output = NULL;

	if(input[c] == 'd' || input[c] == 'i')
		output =  ft_itoa(va_arg(args, int));
		//Recuperer le int sous forme de char *
	else if(input[c] == 'u')
		*len += ft_putunbr(va_arg(args, unsigned int));
		//Recuperer le uint sous forme de char *
	else if(input[c] == 'c')
		ft_putchar(va_arg(args, int));
		//Recuperer le char sous forme de char *
	else if(input[c] == '%')
		ft_putchar(input[c]);
		//Recuperer le % sous forme de char*
	else if(input[c] == 's' && ++i)
		output = ft_strdup(va_arg(args, char*));
	else if(input[c] == 'p' && ++i)
	{
		tmp = ft_convert_base(ft_ultoa(va_arg(args, unsigned long)),
		 "0123456789", "0123456789abcdef");
		output = ft_strjoin("0x", tmp);	
	}
	else if((input[c] == 'x') && ++i)
		output = ft_convert_base(ft_ultoa((unsigned long)va_arg(args, unsigned int)),"0123456789", "0123456789abcdef");
	else if((input[c] == 'X') && ++i)
		output = ft_convert_base(ft_ultoa((unsigned long)va_arg(args, unsigned int)),"0123456789", "0123456789ABCDEF");
	return output;
}

char *proces(const char *str_in, int pos)
{
	char *output;
	char c_to_s[2];

	c_to_s[1] = '\0';
	if(str_in[pos] == '%')
		proces_flag(str_in, pos+1);
	else
	{
		c_to_s[0] = str_in[pos];
		return(ft_strjoin(c_to_s, proces(str_in, pos + 1)))
	}

}

int ft_printf(const char *str_in, ...)
{
 	va_list args;
    
    va_start(args, str_in);
   	


   return 0;
}
