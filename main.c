#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <limits.h>
int main()
{
	//char *test = "Sample text";
	//test = malloc(sizeof(char));
	//ft_printf("%05.4d\n", 16);
	//printf("%05.4d\n", 16);

	//printf("%.10s \n", "1234");
// 	ft_printf("%.10s \n", "1234");

// 	printf("%d\n",ft_printf("s%.10s", (char *)0));
// 	printf("%d\n",printf("s%.10s", (char *)0));

	


// 	printf("%.6s\n", "12345");
// 	ft_printf("%.6s\n", "12345");
// 	ft_printf("%20.30s\n", "0123456789abcdefghijklmnopqrstuv");
// 	printf("%20.30s\n", "0123456789abcdefghijklmnopqrstuv");
// 	ft_printf("%20.30s\n", "0123456789abcdefghijklmnopqrstuv");
// 	printf("%*.*dp%%\n", -20, 15, -12345);
	
// 	ft_printf("%*.*dp%%\n", -20, 15, -12345);
// 	printf("%*d p%%\n", -10, 15, -12345);

// 	ft_printf("%20.30s\n", "0123456789abcdefghijklmnopqrstuv");
// 	printf("%20.30s\n", "0123456789abcdefghijklmnopqrstuv");

// 	//printf("%s\n", );


// 	printf("%.20d \n", 1205);
// 	ft_printf("%.20d \n", 1205);
	//char *output;
	//output = ft_convert_base("1235", "0123456789", "0123456789abcdef");
	//free(output);
// 	printf("Convertions test ; \n------------------------ \n");

// 	printf("%%p test\n");
 	//printf(";%d\n",ft_printf(" 60%14cCJP5SJofg%.1s", '\0', "Ov5Kgkse8TuPy7OQb6n1APg2nRpV89SItmRSEyp2CC8eG38KJ7UtoPwKfzpL9KfNd0vf9EW8V puserlbSGQSudd"));
	//printf(";%d\n",printf(" 60%14cCJP5SJofg%.1s", '\0', "Ov5Kgkse8TuPy7OQb6n1APg2nRpV89SItmRSEyp2CC8eG38KJ7UtoPwKfzpL9KfNd0vf9EW8V puserlbSGQSudd"));
	//ft_printf("0\n");
	unsigned char test[20];
	test[0] = '0';
	test[1] = 160;
	test[2] = 'A';
	test[3] = 'D';
	test[4] = 0;
	printf("%s\n",test );
	printf("%d\n",test[1]);
	//printf(" ; %d\n",ft_printf("0%c", 0));
	//printf(" ; %d\n",printf("0%c fin", 161));
	//write(1,"a\0\n",3);
// 	//printf(" ; %d\n",printf("%.1s%", "")); 
// 	printf(" ; %d\n",ft_printf("%.1s%", "a"));

// 	//printf(" ; %d\n",printf("%.3s%", "")); 
// 	printf(" ; %d\n",ft_printf("%.3s%", ""));

// 	printf(" ; %d\n",printf("%.2%")); 
// 	printf(" ; %d\n",ft_printf("%.2%"));

// 	printf(" ; %d\n",printf("%02i", 0)); 
// 	printf(" ; %d\n",ft_printf("%02i", 0));

// 	printf("%02i", 0);
// 	ft_printf("%02i", 0);

// 	printf("%c", 0); 
// 	ft_printf("%c", 0);

// 	printf("%d\n",printf("%s", "Hello")); 
// 	printf("%d\n",ft_printf("%s", "Hello"));


// 	printf("printf    ; %c : ",0 );
// 	printf("printf    ; %c : ",0 );
	//ft_printf("------------------------ \n%%x test\n");
	//printf("%d\n",ft_printf("ft_printf ; %x : ", 1253));
	//printf("%d\n",printf("printf    ; %x : ",1253 ));

	//ft_printf("------------------------ \n%%X test\n");
	//printf("%d\n",ft_printf("ft_printf ; %X : ", 1253));
	//printf("%d\n",printf("printf    ; %X : ",1253 ));

	// ft_printf("------------------------ \n%%u test\n");
	// printf("%d\n",ft_printf("ft_printf ; %u : ", 25666));
	// printf("%d\n",printf("printf    ; %u : ",25666));

	// ft_printf("------------------------ \n%%c test\n");
	// printf("%d\n",ft_printf("ft_printf ; %c : ", 'Y'));
	// printf("%d\n",printf("printf    ; %c : ",'Y' ));

	// ft_printf("------------------------ \n%%s test\n");
	// printf("%d\n",ft_printf("ft_printf ; %s : ","Sample text"));
	// printf("%d\n",printf("printf    ; %s : ","Sample text" ));

	// ft_printf("------------------------ \n%%i %%d test\n");
	// printf("%d\n",ft_printf("ft_printf ; %i %10d : ",123, 321));
	// printf("%d\n",printf("printf    ; %i %10d : ",123, 321));

	// ft_printf("------------------------ \n%%%% test\n");
	// printf("%d\n",ft_printf("ft_printf ; %% : "));
	// printf("%d\n",printf("printf    ; %% : "));

	// //-0.*
	// printf("Flag testing \n");
	// //-NB S : Si len < nb, add nb-len spaces
	// //si premier = 0, add nombre suite de 0 devqnt le nb
	// //Juste nb direct, nb-len spaces at the left
	// printf("Test with int %4d|\n",123 );
	// printf("Test with int %- 4d|\n",123 );
	// printf("Test with int %s|\n","test" );
	// printf("Test with int %s|\n","test" );
	// printf("Test with int %s|\n","test" );
	// printf("Test with int %s|\n","test" );
	// printf("Test with int %s|\n","test" );


	// ft_printf("Test with int %10s|\n","test" );
	// printf("Test with int %10d |\n",153 );
	// printf("Test with int %.10d |\n",153 );
	// printf("Test with int %*d test %d \n",12, 250, 100 );
	//-0.*
	//ft_printf("sample text, here is a %% %p %x %X and here is another %-u and a %c %s \n",
	 //test, 1253, 1253,  UINT_MAX , 'Y', "test");
	//printf("sample text, here is a %% %p %x %X and here is another %-u and a %c %s \n",
	//test, 1253, 1253 ,UINT_MAX , 'Y', "test");
	//int c;
	//system("leaks a.out");
	return 0;
}