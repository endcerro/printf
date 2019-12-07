
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

# include <unistd.h>

# include <stdio.h>

int 	ft_printf(const char *str_in, ...);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_putchar(char c);
size_t	ft_strlen(const char *str);
void	ft_putunbr(unsigned int n);

unsigned long		ft_atoi_base(char *nb, char *base);
unsigned long		ft_base_is_valid(char *base);
int		mchb_strl(char nb, char *base);
void	ft_addto(char *st, unsigned long *nb, char c);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_ultoa(unsigned long n);


#endif
