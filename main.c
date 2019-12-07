#include "ft_printf.h"
#include <limits.h>
int main(int argc, char const *argv[])
{
	char *test;
	test = malloc(sizeof(char)* 1);

	ft_printf("sample text, here is a %% %p and here is another %u and a %c %s \n",
	 test, UINT_MAX , 'a', "test");
	printf("sample text, here is a %% %p and here is another %u and a %c %s \n",
	 test, UINT_MAX , 'a', "test");
	return 0;
}