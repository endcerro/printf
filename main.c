#include <stdio.h>
#include "header/ft_printf.h"
#include <limits.h>
int main()
{
//printf("%.s\n", "Hello");

	//printf("BASIC TESTING\n---------------------------------------\n");

	char *str = "This is some str for basic testing";
	int nb = 85025;
	//printf(" : %d\n",ft_printf("%d", 0) );
	//printf(" : %d\n",ft_printf("%d", nb));
	//printf(" : %d\n",printf("%d", nb));

	

	//printf(" : %d\n",ft_printf("%010.2d", nb));
	//printf(" : %d\n",printf("%010.2d", nb));

	//	printf(" : %d\n",ft_printf("%010.2i", nb));
	//printf(" : %d\n",printf("%010.2i", nb));

	//printf(" : %d\n",ft_printf("%010.2c", 'A'));
	//printf(" : %d\n",printf("%010.2c", 'A'));


	//ft_printf("on test %s **** %s %s ", "la 1ere str", "2eme str", "3eme str");

	// printf(" : %d\n",ft_printf("%010d", nb));
	// printf(" : %d\n",printf("%010d", nb));


	// printf(" : %d\n",ft_printf("%10c", 'A'));
	// printf(" : %d\n",printf("%10c", 'A'));

	// printf(" : %d\n",ft_printf("%010c", 'A'));
	// printf(" : %d\n",printf("%010c", 'A'));


	// printf(" : %d\n",ft_printf("%10u", 15484884));
	// printf(" : %d\n",printf("%10u", 15484884));

	//printf(" : %d\n",ft_printf("%X", 42));
	//printf(" : %d\n",printf("%X", 42));



	//printf(" : %d\n",printf("%s%d%p%%%i%u%x%X%c","bonjour", 42, str, 42, 42, 42, 42, 'c'));
	//printf(" : %d\n",ft_printf("%s%d%p%%%i%u%x%X%c","bonjour", 42, str, 42, 42, 42, 42, 'c'));

	unsigned long test = 42;

	//char *test = malloc(4);

	//printf(" : %d\n",ft_printf("%x%x%x%x%x%x%x%x%x%x", 42, 42,42, 42, 42,42,42,42,42,42));
	//printf(" : %d\n",printf("%x%x%x%x%x%x%x%x%x%x", test, test,test, test, test, test, test, test,
	// test, test));

//	printf(" : %d\n",printf("%*.*x %*.*X", 1, 50, 500, 1, 0, 10));
//	printf(" : %d\n",ft_printf("%*.*x %*.*X", 1, 50, 500, 1, 0, 10));

	// printf(" : %d\n",printf("%2c", '1'));
	// printf(" : %d\n",ft_printf("%2c", '1'));

//	printf(" : %d\n",printf("c%010.*xeoQG", 0, 5));
//	printf(" : %d\n",ft_printf("c%010.*xeoQG", 0, 5));


//	printf(" : %d\n",printf("%.0s", "Hello"));
//	printf(" : %d\n",ft_printf("%.0s", "Hello"));
	

	printf(" : %d\n",printf("%016.*i", -1, -2147483647));
	printf(" : %d\n",ft_printf("%016.*i", -1, -2147483647));

	// printf(" : %d\n",printf("%010.2i", 0) );
	// printf(" : %d\n",ft_printf("%010.2i", 0) );


	// printf(" : %d\n",printf("%02.1i", 0));
	// printf(" : %d\n",ft_printf("%02.1i", 0));


	// printf(" : %d\n",printf("%02.1i", 0));
	// printf(" : %d\n",ft_printf("%02.1i", 0));


	// printf(" : %d\n",printf("%02.0i", 0) );
	// printf(" : %d\n",ft_printf("%02.0i", 0) );

	// printf(" : %d\n",printf("%.10%"));
	// printf(" : %d\n",ft_printf("%.10%"));


	// printf(" : %d\n",printf("%.0d",0));
	// printf(" : %d\n",ft_printf("%.0d", 0));
	// printf(" : %d\n",printf("%10d",20));
	// printf(" : %d\n",ft_printf("%10d",20));
	

	// // //printf(" : %d\n",ft_printf("%p", str) );
	//char *test = malloc(4);
	// printf(" : %d\n",printf("%p", test));
	// printf(" : %d\n",ft_printf("%p", test));

	// printf(" : %d\n",printf("%x", 25687));
	// printf(" : %d\n",ft_printf("%x", 25687));

	// printf(" : %d\n",printf("%X", 25687));
	// printf(" : %d\n",ft_printf("%X", 25687));

	// printf(" : %d\n",printf("%X", 1235588));
	// printf(" : %d\n",ft_printf("%X", 1235588));


	// printf(" : %d\n",printf("%u", 1123997));
	// printf(" : %d\n",ft_printf("%u", 1123997));

	// printf(" : %d\n",printf("%u", 0));
	// printf(" : %d\n",ft_printf("%u", 0));


	// printf(" : %d\n",printf("%%"));
	// printf(" : %d\n",ft_printf("%%"));

	// printf(" : %d\n",printf("%c",0));
	// printf(" : %d\n",ft_printf("%c",0));


	//free(test);
	//printf(" : %d\n",printf("%.5d", nb));
	//printf(" : %d\n",printf("%.0d", nb));

	//printf(" : %d\n",ft_printf("%d", 10) );
	//printf(" : %d\n",printf("%d", 10) );


	//ft_printf("%.s\n", "Hello");
	//printf("|%p|\n", NULL);
	//ft_printf("|%p|\n", NULL);
	//printf("|%5p|\n", NULL);
	//ft_printf("|%5p|\n", NULL);
	//printf("|%2.9p|\n", 1234);
	//ft_printf("|%2.9p|", 1234);
	return 0;
}