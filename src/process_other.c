/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 03:34:04 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 03:34:07 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				process_di(t_contr *controller)
{
	char			*out;
	int				len;

	out = ft_itoa(va_arg(*(controller->args), int));
	out = applyflags(controller, out);
	len = ft_strlen(out);
	write(1, out, len);
	free(out);
	*(controller->len) += len;
	*(controller->pos) += 1;
}

void				process_s(t_contr *controller)
{
	char			*out;

	out = NULL;
	out = ft_strdup(va_arg(*(controller->args), char *));
	if (out == NULL)
		out = ft_strdup("(null)");
	out = applyflags(controller, out);
	write(1, out, ft_strlen(out));
	*(controller->len) += ft_strlen(out);
	*(controller->pos) += 1;
	free(out);
}

char				*process_0(t_contr *ctlr, int p, int val, char *in)
{
	int				cond;

	cond = (ctlr->flags->vals[p] > 0);
	if (ctlr->flags->flags[p + 1] == '.' &&
		isin(ctlr->str_in[*(ctlr->pos)], "diuxX"))
	{
		if (ctlr->flags->vals[p + 1] < 0)
		{
			if (ctlr->flags->vals[p] > 0 && in[0] == '-')
				return (add_fill_0(in, '0', val, 1));
			return (add_fill(in, ' ' + cond * 16, val, cond));
		}
		if (ft_abs(ctlr->flags->vals[p + 1]) > (int)ft_strlen(in) && val > 1)
			return (add_fill(in, '0', val, 1));
		return (add_fill(in, ' ', val, ctlr->flags->vals[p] > 1));
	}
	else if (isin(ctlr->str_in[*(ctlr->pos)], "diuxX") && in[0] == '-')
	{
		if (ctlr->flags->vals[p] > 0)
			return (add_fill_0(in, '0', val, 1));
		return (add_fill(in, ' ', val, 0));
	}
	else if (in[0] != '\0')
		return (add_fill(in, ' ' + cond * 16, val, cond));
	return (add_fill(in, ' ', val, 1));
}

char				*process_dot(t_contr *ctlr, int p, int val, char *in)
{
	if (ctlr->str_in[*(ctlr->pos)] == 's' && ctlr->flags->vals[p] > 0)
		return (ft_substr(in, 0, ctlr->flags->vals[p]));
	else if (ctlr->str_in[*(ctlr->pos)] == 's' && ctlr->flags->vals[p] == 0)
		return (ft_strdup(""));
	else if (ctlr->str_in[*(ctlr->pos)] == 's')
		return (in);
	else if (isin(ctlr->str_in[*(ctlr->pos)], "di") && in[0] == '-'
		&& ++val && ctlr->flags->vals[p] > 0)
		return (add_fill_0(in, '0', val, 1));
	else if (ft_strlen(in) == 1 && *in == '%')
		return (in);
	else if (ctlr->str_in[*(ctlr->pos)] == 'p')
	{
		if (in[2] == '0' && val <= 0)
			return (ft_strdup("0x"));
		return (add_fill_hex(in, '0', val + 2, 1));
	}
	else
	{
		if (val < 0 && *in == '0')
			return (ft_strdup(""));
		else if (ctlr->flags->vals[p] > 0)
			return (add_fill(in, '0', val, 1));
	}
	return (in);
}

int					getmaxflags(t_contr *controller)
{
	int				i;
	int				pos;
	char			*str_in;

	pos = *(controller->pos);
	str_in = controller->str_in;
	i = 0;
	while (!isin(str_in[i + pos], "disupxXc%"))
		i++;
	return (i);
}
