#include "ft_printf.h"
#include <stdarg.h>


char *process_0(c_contr *controller)
{
	int i;
	char *output;
	char *zeros;
	int cpt;
	char out;

	out = '0';

	i = 0;
	*(controller->pos) += 1;
	output = NULL;
	if(controller->str_in[*(controller->pos)] == '*')
	{
		printf("the case\n");
	}
	int nb = ft_atoi(controller->str_in + *(controller->pos));
	while(isnumber(controller->str_in[*(controller->pos) + i]))
		i++;
	if(controller->str_in[*(controller->pos) + i] == '.')
		out = ' ';
	*(controller->pos) += i;
		output = process_flag(controller);
	if(ft_strlen(output) < nb)
	{
		i = -1;
		zeros = malloc(sizeof(char) * ( nb - ft_strlen(output) + 1 ));
		cpt = nb - ft_strlen(output);
		while(++i < cpt)
			zeros[i] = out;
		zeros[i] = 0;
		output = ft_strjoin(zeros, output);
		free(zeros);
	}
	return(output);
}

char *process_minus(c_contr *controller)
{
	int i;
	char *output;
	char *zeros;
	int cpt;

	i = 0;
	*(controller->pos) += 1;
	output = NULL;	
	if(controller->str_in[*(controller->pos)] == '*')
	{
		printf("the case\n");
	}
	int nb = ft_atoi(controller->str_in + *(controller->pos));
	while(isnumber(controller->str_in[*(controller->pos) + i]))
		i++;
	*(controller->pos) += i;
	output = process_type(controller);
	if(ft_strlen(output) < nb)
	{
		i = -1;
		zeros = malloc(sizeof(char) * ( nb - ft_strlen(output) + 1 ));
		cpt = nb - ft_strlen(output);
		while(++i < cpt)
			zeros[i] = ' ';
		zeros[i] = 0;
		output = ft_strjoin(output,zeros);
		free(zeros);
	}
	return(output);
}

char	*process_star(c_contr *controller)
{
	*controller->pos += 1;
	return(process_flag(controller));
	return 0;
}

char	*process_dot(c_contr *controller)
{

	int i;
	char *output;
	char *zeros;
	int cpt;
	int nb;

	i = 0;
	*(controller->pos) += 1;
	output = NULL;
	if(controller->str_in[*(controller->pos)] == '*')
	{
		nb = va_arg(*(controller->args), int);
		i++;
	}
	else
	{
		nb = ft_atoi(controller->str_in + *(controller->pos));
		while(isnumber(controller->str_in[*(controller->pos) + i]))
			i++;
	}
	*(controller->pos) += i;
	int test = (controller->str_in[*(controller->pos)] == 's');
	output = process_type(controller);
	if(output == NULL)
		return NULL;
	int j = 0;
	while(isnumber(output[j]))
		j++;
	if(test)
		output = ft_substr(output, 0, nb);
	else if(ft_strlen(output) < nb)
	{
		printf("aqui\n");
		i = -1;
		zeros = malloc(sizeof(char) * ( nb - ft_strlen(output) + 1 ));
		cpt = nb - ft_strlen(output);
		while(++i < cpt)
			zeros[i] = '0';
		zeros[i] = 0;

		if(*output == '-')
		{
			output = ft_strjoin(zeros,output+1);
			output = ft_strjoin("-0",output);
		}
		else
			output = ft_strjoin(zeros,output);
		free(zeros);
	}
	return(output);

}

char *process_nb(c_contr *controller)
{
	int i;
	char *output;
	char *zeros;
	int cpt;
	int nb;
	int neg;

	neg = 0;
	i = 0;
	output = NULL;
	nb = ft_atoi(controller->str_in + *(controller->pos));
	while(isnumber(controller->str_in[*(controller->pos) + i]))
		i++;
 	if(controller->str_in[*(controller->pos) + i] == '*')
	{
		nb = va_arg(*(controller->args), int);	
		i++;
	}
	*(controller->pos) += i;
	output = process_flag(controller);
	if((nb - ft_strlen(output)) > 0 )
	{
		
		i = -1;
		cpt = abs(nb) - ft_strlen(output);
		if(cpt <= 0)
			return output;
		zeros = malloc(sizeof(char) * ( cpt + 1 ));
		//printf("cpt = %d\n",cpt);
		while(++i < cpt)
			zeros[i] = ' ';
		zeros[i] = 0;
		if(nb > 0)
			output = ft_strjoin(zeros,output);
		else
			output = ft_strjoin(output,zeros);
		free(zeros);
	}
	printf("here\n");
	return(output);
}

