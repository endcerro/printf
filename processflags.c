#include "ft_printf.h"
#include <stdarg.h>


char *append_char(char *base, char to_add, int count, int order)
{
	int i;
	char *out;
	char *filler;

	i = -1;
	count -= (int)ft_strlen(base);
	if(!(filler = malloc(sizeof(char) * (count + 1))))
		return NULL;
	while (++i < count)
		filler[i] = to_add;
	filler[i] = '\0';
	if (order == 1)
		out = ft_strjoin(filler, base);
	else
		out = ft_strjoin(base, filler);
	free(base); 
	free(filler);	
	return(out);
}

char *process_0(c_contr *controller)
{
	int i;
	char *output;
	char out;
	int nb;

	//printf("process_0\n");
	nb = 0;
	out = '0';
	i = 0;
	*(controller->pos) += 1;
	output = NULL;
	nb = ft_atoi(controller->str_in + *(controller->pos));
	while(isnumber(controller->str_in[*(controller->pos) + i]))
		i++;
	if(controller->str_in[*(controller->pos)] == '*' && ++i)
		nb = va_arg(*(controller->args), int);	
	if(controller->str_in[*(controller->pos) + i] == '.')
		out = ' ';
	*(controller->pos) += i;
	i = *(controller->pos);

	output = process_flag(controller);
	if(controller->str_in[i] == 'i' || controller->str_in[i] == 'd')
	{
		if(output[0] == '-')
		{	
			if((int)ft_strlen(output) < nb)
			{
				output[0] = '0';
				output = append_char(output,out, nb, 1); 
				output[0] = '-';
			}
		}
		else
			output = append_char(output,out, nb, 1);	
		//printf("CASE\n");
	}	
	else if((int)ft_strlen(output) < nb)
		output = append_char(output,out, nb, 1); 
	return(output);
}

char *process_minus(c_contr *controller)
{
	int i;
	char *output;
	int nb;

	//printf("|%c|", controller->str_in[*(controller->pos)]);
	//printf("process_minus \n");

	i = 0;
	//printf("|%c|", controller->str_in[*(controller->pos)]);
	*(controller->pos) += 1;
	//printf("|%c|", controller->str_in[*(controller->pos)]);
	output = NULL;	
	if(controller->str_in[*(controller->pos)] == '*')
	{
		nb = va_arg(*(controller->args), int);
		i++;
		//printf("the case\n");
	}
	//printf("|%d|\n",nb );
	nb = ft_atoi(controller->str_in + *(controller->pos));
	//printf("|%c|\n",controller->str_in[*(controller->pos)] );
	while(isnumber(controller->str_in[*(controller->pos) + i]))
		i++;
	*(controller->pos) += i;
	//printf("|%c|\n",controller->str_in[*(controller->pos)] );
	output = process_flag(controller);
	//printf("|%s|\n",output);
	//printf("|%d|\n",nb );
	if((int)ft_strlen(output) < nb)
	{
		//printf("here\n");
		output = append_char(output,' ', nb, 0);
	}
	//printf("|%s|\n",output);
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
	
	int i;
	char *output;
	char *zeros;
	int cpt;
	int nb;
	char *tmp;

	//printf("process_dot\n");
	//printf("|%c|\n",controller->str_in[*(controller->pos)]);
	i = 0;
	*(controller->pos) += 1;
	output = NULL;
	//printf("AZZ%c\n",controller->str_in[*(controller->pos)]);
	//printf("%s\n",output );
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
		//printf(" i = %d\n", i);
		//printf("nb = %d\n",nb );
	}

	*(controller->pos) += i;
	int test = (controller->str_in[*(controller->pos)] == 's');
	//printf("process_dot\n");
	//printf("|%c|\n",(controller->str_in[*(controller->pos)]));
	output = process_type(controller);
	//printf("after %s\n",output );
	
	if(output != NULL && output[0] == '%')
	{
	//	printf("here\n");
		return output;
	}
	//printf("there\n");
	//Dans le cas ou on rentre dnas test, what is going on
	//printf("nb = %d\n",nb );
	if(output == NULL)
		return NULL;
	//printf("ctla\n");
	//printf("%s\n",output );
	if(test)
	{
	//	printf("ctla\n");
		//printf("ici\n");
		output = ft_substr(output, 0, nb);
	//	printf("|%s|\n",output);
	}
	else if((int)ft_strlen(output) <= nb)
	{
	//	printf("ctla\n");
		//printf("ici ? \n");
		i = -1;
		zeros = malloc(sizeof(char) * ( nb - (int)ft_strlen(output) + 1 ));
		cpt = nb - (int)ft_strlen(output);
		while(++i < cpt)
			zeros[i] = '0';
		zeros[i] = 0;
		if(*output == '-')
		{
	//		printf("chelou zone\n");
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
	if(nb == 0 && output[0] == '0'){
		//printf("here\n");
		return (ft_strdup(""));
	}
		
		///printf("case\n");
	
	//printf("%s\n",output );
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
	//printf("process_nb\n");
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

		//append_char(char *base, ' ', cpt, int order);
		i = -1;
		cpt = abs(nb) - (int)ft_strlen(output);
		if(cpt <= 0)
			return output;
		zeros = malloc(sizeof(char) * ( cpt + 1 ));
		while(++i < cpt)
			zeros[i] = ' ';
		//printf("nded\n");
		zeros[i] = '\0';
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

