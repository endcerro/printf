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

int process_type(char *input, int c, va_list args, int *len)
{

	//GERE FLAGS 0 - * .
	int i;
	char *tmp;
	int j;
	int nb;
	nb = 0;
	i = 0;
	if((input[c] == 'd' || input[c] == 'i') && ++i)
		*len += ft_putnbr(va_arg(args, int));
	else if(input[c] == 'u' && ++i)
		*len += ft_putunbr(va_arg(args, unsigned int));
	else if(input[c] == 'c' && ++i && ++(*len))
		ft_putchar(va_arg(args, int));
	else if(input[c] == '%' && ++i && ++(*len))
		ft_putchar(input[c]);
	else if(input[c] == 's' && ++i)
		*len += ft_putstr(va_arg(args, char*));
	else if(input[c] == 'p' && ++i)
	{
		ft_putstr("0x");
		tmp = ft_convert_base(ft_ultoa(va_arg(args, unsigned long)),
		 "0123456789", "0123456789abcdef");
		*len += ft_strlen(tmp) + 2;
		ft_putstr(tmp);
	}
	else if((input[c] == 'x') && ++i)
	{
		tmp = ft_convert_base(ft_ultoa((unsigned long)va_arg(args, unsigned int)),"0123456789", "0123456789abcdef");
		*len += (int)ft_strlen(tmp);
		ft_putstr(tmp);
	}
	else if((input[c] == 'X') && ++i)
	{
		tmp = ft_convert_base(ft_ultoa((unsigned long)va_arg(args, unsigned int)),"0123456789", "0123456789ABCDEF");
		*len += (int)ft_strlen(tmp);
		ft_putstr(tmp);	
	}
	else if(input[c] == '-')
	{
		nb = ft_atoi_base(input + c + 1, "0123456789");
		j = 1;
		while(isnumber(input[c + j]))
			j++;
		c += process_type(input, c + j, args, len);
		putspace(nb - j - 1);
		i += j + 1;
	}
	else if(isnumber(input[c]) && input[c] != '0')
	{
		int tmp;
		tmp = *len;
		nb = ft_atoi_base(input + c, "0123456789");
		j = 0;
		while(isnumber(input[c + j]))
			j++;
		printf(" j = %d",j );
		printf(" nbspc = %d",nb - j - 1);
		
		putspace(nb - j - 1);
		
		c += process_type(input, c + j, args, len);
		//printf("%s\n", );
		i += j + 1;
	}
	else if(input[c] == '0')
	{

	}
	//else if(input[c] == '0' || input[c] == '-' || input[c] == '*' || input[c] == '.')
		//if(process_type(input, c+1, args, len) > 0)
			//i += 2;
	
	return i;
}

int ft_printf(const char *str_in, ...)
{
 	va_list args;
    
    int i;
    int j;
   	int len;

   	len = 0;
    j = 0;
    char *cp;

    va_start(args, str_in);
    cp = (char *)str_in;

    i = -1;

    while(cp[++i] != '\0')
    {
    	if(cp[i] == '%')
    	{
    		if((j = process_type(cp,i + 1, args, &len)) && j > 0)
    			i += j;
    		else
    		{
    			ft_putchar(cp[i]);
    			len++;
    		}
      	}
      	else
      	{
      		ft_putchar(cp[i]);
      		len++;
      	}
    }

    va_end(args);
	return len;
}
