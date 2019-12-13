#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int i;

	i = 0; 
	if (n == -2147483648 && (i = 11))
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		i++;
		i += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
		i++;
	}
	else if(++i)
		ft_putchar(n + '0');
	return i;
}

int		ft_putunbr(unsigned int n)
{
	int i = 0;
	if (n >= 10)
	{
		i += ft_putunbr(n / 10);
		i++;
		ft_putchar(n % 10 + '0');
	}
	else
	{
		ft_putchar(n + '0');
		i++;
	}
	//printf("numlen = %d\n",i );
	return(i);
}

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
	//printf("NLFT\n");
	if(str == 0)
		return 0;
	cpt = 0;
	while (str[cpt])
		cpt++;
	return (cpt);
}

void putspace(int nb)
{
	int i;

	i = -1;
	while(++i < nb)
		write(1," ",1);
}
int isnumber(char c)
{
	if(c >= '0' && c <= '9')
		return 1;
	return 0;
}