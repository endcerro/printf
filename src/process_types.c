#include "ft_printf.h"

void process_di(t_contr *controller)
{
	char *out;

	out = ft_itoa(va_arg(*(controller->args), int));
	
	//process flags
	//printf("out before = %s \n", out);
	
	out = applyflags(controller, out);
	//printf("out after = %s \n", out);
	int len = ft_strlen(out);
	write(1,out, len);
	free(out);
	*(controller->len) += len;
	*(controller->pos) += 1; // +nb de flags
}
void process_s(t_contr *controller)
{
	char *out;
	//printf("S PROCESS \n");
	out = ft_strdup(va_arg(*(controller->args), char *));
	if (out == NULL)
	{
		out = ft_strdup("(null)");
	}
	
	out = applyflags(controller, out);
	int len = ft_strlen(out);


	write(1,out, len);
	*(controller->len) += len;
	*(controller->pos) += 1;
	free(out);
	//printf("S PROCESS DONE \n");
	//printf("weout\n");
	//printf("end pos in process_s= %d\n",*controller->pos);
}

void process_p(t_contr *controller)
{
	//controller = NULL;
	char			*out;
	char			*tmp;
	int 			len;
	unsigned long	number;

	number = va_arg(*(controller->args), unsigned long);
	out = ft_ultoa(number);
	tmp = ft_convert_base(out, "0123456789", "0123456789abcdef");
	
	free(out);
	out = ft_strjoin("0x", tmp);
	free(tmp);
	out = applyflags(controller, out);
	len = ft_strlen(out);
	write(1,out, len);
	*(controller->len) += len;
	*(controller->pos) += 1;
	free(out);
}

void process_x(t_contr *controller, char c)
{
	char			*out;
	char			*tmp;
	int 			len;
	unsigned int	number;

	//number = 0;
	number = va_arg(*(controller->args), unsigned int);

	//printf("\nnumber from args = |%u|\n",number );
	//unsigned long tmp2 = va_arg(*(controller->args), unsigned long);
	//printf("\nnumber from args 2 = %lu\n",tmp2 );
	//CHANGEMENT ICI
	tmp = ft_ultoa((unsigned long)number);
	//printf("tmp = %s\n",tmp );
	if(c == 'x'){
		out = ft_convert_base(tmp, "0123456789", "0123456789abcdef");
	//printf("OUTPUT x = %s\n",out );
	}
	else
	{
	// 	unsigned long tmp2 = va_arg(*(controller->args), unsigned long);
	// printf("\nnumber from args 2 = %lu\n",tmp2 );
		out = ft_convert_base(tmp, "0123456789", "0123456789ABCDEF");
	//	printf("OUTPUT X = %s\n",out );
	}
	free(tmp);
	//printf("\nOUT  =  %s \n", out);
	out = applyflags(controller, out);
	len = ft_strlen(out);

	write(1, out, len);
	*(controller->len) += len;
	*(controller->pos) += 1;

	free(out);
}

// void process_x(t_contr *controller, char c)
// {
// 	char			*out;
// 	char			*tmp;
// 	int 			len;
// 	unsigned long	number;

// 	//number = 0;
// 	number = va_arg(*(controller->args), unsigned long);

// 	printf("\nnumber from args = |%lu|\n",number );
// 	//unsigned long tmp2 = va_arg(*(controller->args), unsigned long);
// 	//printf("\nnumber from args 2 = %lu\n",tmp2 );
// 	//CHANGEMENT ICI
// 	tmp = ft_ultoa(number);
// 	//printf("tmp = %s\n",tmp );
// 	if(c == 'x'){
// 		out = ft_convert_base(tmp, "0123456789", "0123456789abcdef");
// 	//printf("OUTPUT x = %s\n",out );
// 	}
// 	else
// 	{
// 	// 	unsigned long tmp2 = va_arg(*(controller->args), unsigned long);
// 	// printf("\nnumber from args 2 = %lu\n",tmp2 );
// 		out = ft_convert_base(tmp, "0123456789", "0123456789ABCDEF");
// 	//	printf("OUTPUT X = %s\n",out );
// 	}
// 	free(tmp);
// 	//printf("\nOUT  =  %s \n", out);
// 	len = ft_strlen(out);

// 	write(1, out, len);
// 	*(controller->len) += len;
// 	*(controller->pos) += 1;

// 	free(out);
// }

void process_u(t_contr *controller)
{
	//controller = NULL;
	int len;
	char *out;

	out = ft_ultoa(va_arg(*(controller->args),unsigned int));
	out = applyflags(controller, out);
	len = ft_strlen(out);
	write(1, out, len);
	*(controller->len) += len;
	*(controller->pos) += 1;
	free(out);
}

void process_pr(t_contr *controller)
{
	char *out;
	int len;

	out = ft_strdup("%");
	//process flags ? 
	out = applyflags(controller, out);
	len = ft_strlen(out);
	write(1, out, len);
	*(controller->len) += len;
	*(controller->pos) += 1;
}

void process_c(t_contr *controller)
{
	char *out;
	int len;
	int i;
	unsigned char c[1];

	c[0] = va_arg(*(controller->args), int);

	i = 0;
	out = ft_strdup("c");
	//printf("b4 flags\n |%s| \n", out);
	out = applyflags(controller, out);
	//printf("af flags\n |%s| \n", out);
	len = ft_strlen(out);
	
	while (i < len)
	{
		if(out[i] == 'c')
			write(1, c, 1);
		else
			write(1, out + i, 1);
		i++;	
	}
	free(out);
	*(controller->len) += len;
	*(controller->pos) += 1;
}