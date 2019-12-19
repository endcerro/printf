#include <stdio.h>
#include "header/ft_printf.h"

int main()
{

	printf("%.p\n", NULL);
	ft_printf("%.p\n", NULL);
	printf("%p\n", NULL);
	ft_printf("%p", NULL);
	return 0;
}