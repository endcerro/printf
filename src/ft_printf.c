/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:08:05 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/18 21:50:51 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int isin(char c, char *str)
{
	int i;

	i = 0;
	while(str[i] != c && str[i] != '\0')
		i++;
	if(str[i] == c)
		return (1);
	return (0);
}

char	*add_fill(char *base, char fill, int cpt, int order)
{
	char *to_add;
	int i;
	char *tmp;

	i = 0;
	if(cpt <= 0)
		return base;
	if(!(to_add = malloc(sizeof(char) * (cpt + 1))))
		return (NULL);
	while(i < cpt)
		to_add[i++] = fill;
	to_add[i] = '\0';
	if(order == 1)
		tmp = ft_strjoin(to_add, base);
	else
		tmp = ft_strjoin(base, to_add);
	free(base);
	free(to_add);
	return (tmp);
}


char *applyflags(t_contr *controller, char *in)
{
	int p;
	char *out;
	int val;


	if(controller->flags == NULL)
		return in;
	val = 0;
	p = (controller->flags->nbfl) - 1;
	out = NULL;

	while(p >= 0 && *in >= 0)
	{
		val = ft_abs(controller->flags->vals[p]) - ft_strlen(in);
	 	if(controller->flags->flags[p] == '0')
	 	{	
	 		if(controller->flags->flags[p + 1] == '.' && isin(controller->str_in[*(controller->pos)], "diuxX"))
 			{
 				if(controller->flags->vals[p + 1] < 0)
 				{	
					if(controller->flags->vals[p] > 0)
 					{
 						if(in[0] == '-')
 						{
 							in[0] = '0';
 							out = add_fill(in, '0', val, 1);
 							out[0] = '-';
 						}
 						else
							out = add_fill(in, '0', val, 1);				
 					}
					else
						out = add_fill(in, ' ', val, 0);
				}
 				else if(ft_abs(controller->flags->vals[p + 1]) > (int)ft_strlen(in) && val > 1)
 					out = add_fill(in, '0', val, 1);
 				else
	 			{	
	 				if(controller->flags->vals[p] > 1)
	 					out = add_fill(in, ' ', val, 1	);
	 				else
	 					out = add_fill(in, ' ', val, 0);
	 			}
	 		}
 			else if (isin(controller->str_in[*(controller->pos)], "diuxX") && in[0] == '-')
 			{
				if(controller->flags->vals[p] > 0)
				{
					in[0] = '0';
 					out = add_fill(in, '0', val, 1);
 					out[0] = '-';
 				}
 				else
 					out = add_fill(in, ' ', val, 0);
 			}
 			else if(*in != '\0')
 			{

 				if(controller->flags->vals[p] < 0)
					out = add_fill(in, ' ', val, 0);
				else
 					out = add_fill(in, '0', val, 1);
 			}
 			else
 				out = add_fill(in, ' ', val, 1);
 	 	}
		else if(controller->flags->flags[p] == 'n')
		{	
			if(isin(controller->str_in[*(controller->pos)], "c") && controller->flags->vals[p] <= 0)
				out = add_fill(in, ' ', val, 0);
			else
				out = add_fill(in, ' ', val, 1);
		}
		else if(controller->flags->flags[p] == '-')
			out = add_fill(in, ' ', val, 0);
		else if(controller->flags->flags[p] == '.')
 		{
 			if(controller->flags->vals[p] == 0)
 				out = in;
 			if(isin(controller->str_in[*(controller->pos)], "s"))
 			{
 				if(controller->flags->vals[p] > 0)
 					out = ft_substr(in, 0, ft_abs(controller->flags->vals[p]));
 				else if(controller->flags->vals[p] == 0)
 					out = ft_strdup("");
 				else
 					out = in;
 			}
 			else if (isin(controller->str_in[*(controller->pos)], "di") && in[0] == '-')
 			{
				val++;
 				if(controller->flags->vals[p] > 0)
				{

					in[0] = '0';
 					out = add_fill(in, '0', val, 1);
 					out[0] = '-';
 				}
			}
 			else if (ft_strlen(in) == 1 && *in == '%' )
 				out = in;
 			else if(controller->str_in[*(controller->pos)] == 'p')
 			{
 				if(in[2] == '0' && val <= 0)
 					out = ft_strdup("0x");
 				else
 				{
 					in[1] = '0';
 					out = add_fill(in, '0', val + 2, 1);
 					out[1] = 'x';
 				}
 			}
 			else
 			{
 				if(val < 0 && *in == '0')	
 					out = ft_strdup("");
 				else if (controller->flags->vals[p] > 0)
 					out = add_fill(in, '0', val, 1);
 				else
 					out = add_fill(in, ' ', 0, 0);
 			}

 		}
 		if(out != NULL)
 			in = out;
 		p--;
	}
	if (out != NULL)
		return out;
	else
		return in;
}



int		getmaxflags(t_contr *controller)
{
	int i;
	int pos;
	char *str_in;

	pos = *(controller->pos);
	str_in = controller->str_in;
	i = 0;
	
	while(!isin(str_in[i + pos], "disupxXc%"))
		i++;
	return i;
}

void getflags(t_contr *controller, int i)
{
	char *flag;
	int *nb;
	int pos;
	int j = *(controller->pos);
	int p;
	t_flags *flags;

	p = 0;
	pos = 0;
	if(!(flags = malloc(sizeof(t_flags))))
	 	return ;
	 if(!(nb = malloc(sizeof(int) * i)))
	 	return ;
	 if(!(flag = malloc(sizeof(char) * i)))
	 	return ;
	flags->flags = flag;
	flags->vals = nb;	
	while(!isin(controller->str_in[j + pos], "disupxXc%") && controller->str_in[j + pos] != '\0')
	{	
		if(isin(controller->str_in[j + pos], "123456789*"))
		{
			flag[p] = 'n';
			if(controller->str_in[j + pos] == '*')
			{
				nb[p] = va_arg(*(controller->args), int);	
				if(nb[p] < 0)
				{
					flag[p] = '-';
					nb[p] = ft_abs(nb[p]);
				}
				pos += 1;
			}
			else
			{
				nb[p] = ft_atoi((const char *)controller->str_in + j + pos);
				while(isin(controller->str_in[j + pos], "0123456789"))
					pos++;
			} 
		}
		else if(controller->str_in[j + pos] == '-')
		{
			flag[p] = '-';
			if(controller->str_in[j + pos + 1] == '*')
			{
				nb[p] = va_arg(*(controller->args), int);	
				pos += 2;
			}
			else
			{
				pos++;
				nb[p] = ft_atoi((const char *)controller->str_in + j + pos);
				while(isin(controller->str_in[j + pos], "0123456789") && controller->str_in[j + pos] != '\0')
					pos++;
			}
		}
		else if(controller->str_in[j + pos] == '0')
		{
			flag[p] = '0';
			if(controller->str_in[j + pos + 1] == '*')
			{
				nb[p] = va_arg(*(controller->args), int);	
				pos += 2;
			}
			else
			{
				pos++;
				nb[p] = ft_atoi((const char *)controller->str_in + j + pos);
				while(isin(controller->str_in[j + pos], "0123456789"))
					pos++;	
			}
		}
		else if(controller->str_in[j + pos] == '.')
		{
			flag[p] = '.';
			if(controller->str_in[j + pos + 1] == '*')
			{
				nb[p] = va_arg(*(controller->args), int);
				pos += 2;
			}
			else
			{
				pos++;
				nb[p] = ft_atoi((const char *)controller->str_in + j + pos);
				while(isin(controller->str_in[j + pos], "0123456789"))
					pos++;	
			}
		}
		else
		{
			if(controller->str_in[*(controller->pos)] == '\0')
				printf("coucou\n");
			flags->nbfl = p;
			*(controller->pos) += pos;
			controller->flags = flags;
			return;
		}
		p++;
	}
 	flags->nbfl = p;
	*(controller->pos) += pos;
	controller->flags = flags;
}

void free_flags(t_contr *controller)
{
	free(controller->flags->flags);
	free(controller->flags->vals);
	free(controller->flags);
}

void	process(t_contr *controller)
{
	
	char c;
	int i;
	
	i = *(controller->pos);
	c = controller->str_in[i];
	getflags(controller, getmaxflags(controller));
	c = controller->str_in[*(controller->pos)];
	if(c == 'd' || c == 'i')
		process_di(controller);
	else if (c == 's')
		process_s(controller);
	else if (c == 'u')
		process_u(controller);
	else if (c == 'p')
		process_p(controller);
	else if (c == 'X' || c == 'x')
		process_x(controller, c);
	else if (c == '%')
		process_pr(controller);
	else if (c == 'c')
		process_c(controller);
	else
		write(1,"",1);
	free_flags(controller);
}

int				ft_printf(const char *str_in, ...)
{
	struct s_contr	*controller;
	va_list			args;
	int				i;
	int 			len;

	len = 0;
	i = 0;
	if (!(controller = malloc(sizeof(t_contr))))
		return (0);
	controller->str_in = (char *)str_in;
	controller->args = &args;
	controller->len = &len;
	controller->pos = &i;
	va_start(args, str_in);
	while(str_in[i] != '\0')
	{
		if (str_in[i] == '%' && ++i)
			process(controller);
		else
		{
			write(1,str_in + i,1);
			len++;
			i++;
		}
	}
	free(controller);
	va_end(args);
//	system("leaks a.out");
	return (len);
}
