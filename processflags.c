#include "ft_printf.h"

char *process_0(c_contr *controller)
{
	int i;
	char *output;
	char *zeros;
	int cpt;

	i = 0;
	*(controller->pos) += 1;
	output = NULL;
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
			zeros[i] = '0';
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

char *process_nb(c_contr *controller)
{
	int i;
	char *output;
	char *zeros;
	int cpt;

	i = 0;
	output = NULL;
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
		output = ft_strjoin(zeros,output);
		free(zeros);
	}
	return(output);
}