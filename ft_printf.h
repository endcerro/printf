
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

# include <unistd.h>

#include <stdio.h>

# include <stdarg.h>

# include "libft.h"


typedef struct		c_list
{
	int 			*len;
	int 			*pos;
	va_list			*args;
	char 			*str_in;
}					c_contr;

int 				ft_printf(const char *str_in, ...);
char				*ft_ultoa(unsigned long n);
char 				*process_0(c_contr *controller);
char 				*process_type(c_contr *controller);
char				*process_dot(c_contr *controller);
char 				*process_minus(c_contr *controller);
char 				*process_nb(c_contr *controller);
char 				*process(c_contr *controller);
char 				*process_flag(c_contr *controller);
char				*process_star(c_contr *controller);
char				*process_s(c_contr *controller);
char				*process_p(c_contr *controller);
char				*process_x(c_contr *controller, char x);
void				sub_process0(int nb, char *output, char c);
char 				*append_char(char *b, char ta, int ct, int odr);

#endif
