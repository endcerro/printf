#include "ft_printf.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

void	ft_putunbr(unsigned int n)
{
	if (n >= 10)
	{
		ft_putunbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

void	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen((const char*)s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t cpt;

	cpt = 0;
	while (str[cpt])
		cpt++;
	return (cpt);
}
