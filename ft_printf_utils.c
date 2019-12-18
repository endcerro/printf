#include "ft_printf.h"

unsigned char	*process_s(c_contr *controller)
{
	unsigned char *tmp;

	tmp = va_arg(*(controller->args), unsigned char*);
	if (tmp == NULL)
	{
		//tmp = (unsigned char*)"(null)";
		return (ft_ustrdup((unsigned char *)"(null)"));
	}
	return (ft_ustrdup(tmp));
}

unsigned char	*process_p(c_contr *controller)
{
	char *output;
	char *tmp;
	unsigned char *outuns;


	output = ft_ultoa(va_arg(*(controller->args), unsigned long));
	tmp = ft_convert_base(output, "0123456789", "0123456789abcdef");
	free(output);
	output = ft_strjoin("0x", tmp);
	free(tmp);
	outuns = ft_ustrdup((unsigned char *)output);
	free(output);
	return (outuns);
}

unsigned char	*process_x(c_contr *controller, char x)
{
	char *tmp;
	unsigned char *output;

	tmp = ft_ultoa((unsigned long)va_arg(*(controller->args), unsigned int));
	if (x == 'x')
		output = (unsigned char *)ft_convert_base(tmp, "0123456789", "0123456789abcdef");
	else
		output = (unsigned char *)ft_convert_base(tmp, "0123456789", "0123456789ABCDEF");
	free(tmp);
	return (output);
}

void	sub_process0(int nb, unsigned char **output, char c)
{
	//printf("c = %d nb = |%d| s = |%s|\n",c, nb ,output );
	//printf("nb = %d, len = %d, abs = %d \n",nb,(int)ft_ustrlen(output), ft_abs(nb)  );
	//char *tmp;
	if(nb < 0 && ((int)ft_ustrlen(*output) < ft_abs(nb)))
	{
		//printf("1\n");
		*output = append_char(*output, ' ', ft_abs(nb), 0); 
	}
	else if(*output[0] == '-' && (int)ft_ustrlen(*output) < nb)
	{
		//printf("2\n");
		*output[0] = '0';
		*output = append_char(*output, c, nb, 1); 
		*output[0] = '-';
	}
	else
	{
		//printf("c = %d nb = |%d| s = |%s|\n",c, nb ,output );
		//printf("3\n");
		//printf("|%s|\n",*output );
		*output = append_char(*output, c, nb, 1);
	}
	//printf("|%s|\n",*output );
}
