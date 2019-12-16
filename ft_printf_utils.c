#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen((const char*)s));
	return(ft_strlen((const char*)s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t cpt;
	if(str == 0)
		return 0;
	cpt = 0;
	while (str[cpt])
		cpt++;
	return (cpt);
}

int isnumber(char c)
{
	if(c >= '0' && c <= '9')
		return 1;
	return 0;
}