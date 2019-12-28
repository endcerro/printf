/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:08:05 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 10:06:04 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*applyflags(t_contr *controller, char *in)
{
	int				p;
	char			*out;
	int				val;

	p = (controller->flags->nbfl);
	out = ft_strdup(in);
	free(in);
	while (--p >= 0 && *out >= 0)
	{
		val = ft_abs(controller->flags->vals[p]) - ft_strlen(out);
		if (controller->flags->flags[p] == '0')
			out = process_0(controller, p, val, out);
		else if (controller->flags->flags[p] == 'n')
			out = add_fill(out, ' ', val,
				(!(isin(controller->str_in[*(controller->pos)], "c") &&
					controller->flags->vals[p] <= 0)));
		else if (controller->flags->flags[p] == '-')
			out = add_fill(out, ' ', val, 0);
		else if (controller->flags->flags[p] == '.')
			out = process_dot(controller, p, val, out);
	}
	return (out);
}

void				getflags(t_contr *controller, int i)
{
	int				pos;
	int				j;
	int				p;
	char			c;

	j = *(controller->pos);
	p = 0;
	pos = 0;
	get_flag_contr(controller, i);
	c = controller->str_in[j + pos];
	while (!isin(c, "disupxXc%") && c != '\0')
	{
		if (!sub_proc_getflags(controller, &pos, j, p))
		{
			controller->flags->nbfl = p;
			*(controller->pos) += pos;
			return ;
		}
		c = controller->str_in[j + pos];
		p++;
	}
	controller->flags->nbfl = p;
	*(controller->pos) += pos;
}

void				free_flags(t_contr *controller)
{
	free(controller->flags->flags);
	free(controller->flags->vals);
	free(controller->flags);
}

void				process(t_contr *controller)
{
	char			c;
	int				i;

	i = *(controller->pos);
	c = controller->str_in[i];
	getflags(controller, getmaxflags(controller));
	c = controller->str_in[*(controller->pos)];
	if (c == 'd' || c == 'i')
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
		write(1, "", 1);
	free_flags(controller);
}

int					ft_printf(const char *str_in, ...)
{
	struct s_contr	*controller;
	va_list			args;
	int				i;
	int				len;

	len = 0;
	i = 0;
	if (!(controller = malloc(sizeof(t_contr))))
		return (0);
	controller->str_in = (char *)str_in;
	controller->args = &args;
	controller->len = &len;
	controller->pos = &i;
	va_start(args, str_in);
	while (str_in[i] != '\0')
	{
		if (str_in[i] == '%' && ++i)
			process(controller);
		else if (++len)
			write(1, str_in + i++, 1);
	}
	free(controller);
	va_end(args);
	return (len);
}
