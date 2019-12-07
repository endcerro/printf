#include "ft_printf.h"
#include <stdarg.h>

int process_type(char c, va_list args)
{
	int i;

	i = 0;
	if((c == 'd' || c == 'i') && ++i)
		ft_putnbr(va_arg(args, int));
	else if(c == 'u' && ++i)
		ft_putunbr(va_arg(args, unsigned int));
	else if(c == 'c' && ++i)
		ft_putchar(va_arg(args, int));
	else if(c == '%' && ++i)
		ft_putchar(c);
	else if(c == 's' && ++i)
		ft_putstr(va_arg(args, char*));
	else if(c == 'p' && ++i)
	{
		ft_putstr("0x");
		ft_putstr(ft_convert_base(ft_ultoa(va_arg(args, unsigned long)),
		 "0123456789", "0123456789abcdef"));
	}
	else if((c == 'x' || c == 'X') && ++i)
		printf("!IMP");

	return i;
}

int ft_printf(const char *str_in, ...)
{
 	va_list args;
    va_start(args, str_in);
    int i;
    char *cp;

    cp = (char *)str_in;

    i = -1;

    while(cp[++i] != '\0')
    {
    	if(cp[i] == '%')
    	{
    		if(process_type(cp[i + 1], args) > 0)
    			i++;
    		else
    			ft_putchar(cp[i]);
      	}
      	else
      	{
      		ft_putchar(cp[i]);
      	}
    }

    va_end(args);
	return 0;
}