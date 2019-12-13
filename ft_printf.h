
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

# include <unistd.h>

# include <stdio.h>


typedef struct		c_list
{
	int 			*len;
	int 			*pos;
	va_list			*args;
	char 			*str_in;
}					c_contr;
int 				ft_printf(const char *str_in, ...);
//int					ft_putnbr(int n);
int					ft_putstr(char *s);
void				ft_putchar(char c);
size_t				ft_strlen(const char *str);
int					ft_putunbr(unsigned int n);
void 				putspace(int nb);
int 				isnumber(char c);
unsigned long		ft_atoi_base(char *nb, char *base);
unsigned long		ft_base_is_valid(char *base);
int					mchb_strl(char nb, char *base);
void				ft_addto(char *st, unsigned long *nb, char c);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
char				*ft_ultoa(unsigned long n);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
char 				*process_0(c_contr *controller);
int					ft_atoi(const char *in);
int					ft_isdigit(int c);
char 				*process_type(c_contr *controller);
char				*process_dot(c_contr *controller);
char 				*process_minus(c_contr *controller);
char 				*process_nb(c_contr *controller);
char 				*process(c_contr *controller);
char 				*process_flag(c_contr *controller);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*process_star(c_contr *controller);


#endif
