#include "ft_printf.h"

char *process_0(const char str_in*, int pos)
{
	int i;

	char *tmp;
	char *output;
	char *zeros;
	i = 0;


	int nb = ft_itoa(str_in + pos);

	while(isnumber(str_in[pos + i]))
		i++;

	output = process_type(str_in, pos + i);

	if(ft_strlen(tmp) < nb)
	{
		i = 0;
		int tmp = ft_strlen(tmp) - nb;
		zeros = malloc(sizeof(char) * ( tmp + 1 ));
		while(i < tmp)
			zeros[i++] = '0';
		zeros[i] = 0;
		output = ft_strjoin(zeros, output);
	}
	return(output);
}