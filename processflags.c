#include "ft_printf.h"
#include <stdarg.h>


char *process_0(c_contr *controller)
{
	int i;
	char *output;
	char *zeros;
	char out;
	char *tmp;
	int nb;

	nb = 0;
	out = '0';

	i = 0;
	*(controller->pos) += 1;
	output = NULL;
	if(controller->str_in[*(controller->pos)] == '*')
	{
		printf("the case\n");
	}

	nb = ft_atoi(controller->str_in + *(controller->pos));
	while(isnumber(controller->str_in[*(controller->pos) + i]))
		i++;
	if(controller->str_in[*(controller->pos) + i] == '.')
		out = ' ';
	*(controller->pos) += i;
		output = process_flag(controller);
	if((int)ft_strlen(output) < nb)
	{
		i = -1;
		zeros = malloc(sizeof(char) * ( nb - (int)ft_strlen(output) + 1 ));
		nb = nb - (int)ft_strlen(output);
		while(++i < nb)
			zeros[i] = out;
		zeros[i] = 0;
		tmp = ft_strjoin(zeros, output);
		free(output); 
		free(zeros);
		output = tmp;
	}
	return(output);
}

char *process_minus(c_contr *controller)
{
	int i;
	char *output;
	char *zeros;
	int cpt;
	char *tmp;

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
	if((int)ft_strlen(output) < nb)
	{
		i = -1;
		zeros = malloc(sizeof(char) * ( nb - (int)ft_strlen(output) + 1 ));
		cpt = nb - (int)ft_strlen(output);
		while(++i < cpt)
			zeros[i] = ' ';
		zeros[i] = 0;
		tmp = ft_strjoin(output,zeros);
		free(zeros);
		free(output);
		output = tmp;
	}
	return(output);
}

char	*process_star(c_contr *controller)
{
	*controller->pos += 1;
	return(process_flag(controller));
	//return 0;
}

char	*process_dot(c_contr *controller)
{
	//printf("HERE\n");
	int i;
	char *output;
	char *zeros;
	int cpt;
	int nb;
	char *tmp;

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
	
	//Dans le cas ou on rentre dnas test, what is going on
	if(output == NULL)
		return NULL;
	if(test)
		output = ft_substr(output, 0, nb);
	else if((int)ft_strlen(output) < nb)
	{
		i = -1;
		zeros = malloc(sizeof(char) * ( nb - (int)ft_strlen(output) + 1 ));
		cpt = nb - (int)ft_strlen(output);
		while(++i < cpt)
			zeros[i] = '0';
		zeros[i] = 0;
		if(*output == '-')
		{
			tmp = ft_strjoin(zeros,output+1);
			free(output);
			output = ft_strjoin("-0",tmp);
			free(tmp);
		}
		else
		{
			tmp = ft_strjoin(zeros,output);
			free(output);
			output = tmp;
		}
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
	char *tmp;

	//printf("nded\n");
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
	//printf("inllop\n");
	//printf("nb = %d\n", nb);
	if((abs(nb) - (int)ft_strlen(output)) > 0 )
	{

		
		i = -1;
		cpt = abs(nb) - (int)ft_strlen(output);
		if(cpt <= 0)
			return output;
		zeros = malloc(sizeof(char) * ( cpt + 1 ));
		while(++i < cpt)
			zeros[i] = ' ';
		//printf("nded\n");
		zeros[i] = 0;
		//printf("nded\n");
		if(nb > 0)
		{
			tmp = ft_strjoin(zeros,output);
			free(output);
			output = tmp;
		}
		else
		{
			tmp = ft_strjoin(output,zeros);
			free(output);
			output = tmp;
		}
		free(zeros);
	}
	return(output);
}

