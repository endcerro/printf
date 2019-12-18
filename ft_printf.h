
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

# include <unistd.h>

# include <stdarg.h>

#include <stdio.h>

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
unsigned char 				*process_0(c_contr *controller);
unsigned char 				*process_type(c_contr *controller);
unsigned char				*process_dot(c_contr *controller);
unsigned char 				*process_minus(c_contr *controller);
unsigned char 				*process_nb(c_contr *controller);
unsigned char 				*process(c_contr *controller);
unsigned char 				*process_flag(c_contr *controller);
unsigned char				*process_star(c_contr *controller);
unsigned char				*process_s(c_contr *controller);
unsigned char				*process_p(c_contr *controller);
unsigned char				*process_x(c_contr *controller, char x);
void						sub_process0(int nb, unsigned char **output, char c);
unsigned char				*append_char(unsigned char *base, char to_add, int count, int order);
void 						ft_putustr(unsigned char* in);
int 						ft_ustrlen(unsigned char *str);
unsigned char				*ft_ustrdup(unsigned char *s1);
unsigned char				*ft_ustrjoin(const unsigned char *s1, const unsigned char *s2);
unsigned char				*ft_usubstr(unsigned char *s, unsigned int start, size_t len);

#endif
