/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 05:21:36 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 05:21:37 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flag_contr(t_contr *controller, int i)
{
	t_flags *flags;

	if (!(flags = malloc(sizeof(t_flags))))
		return ;
	if (!(flags->vals = malloc(sizeof(int) * i)))
		return ;
	if (!(flags->flags = malloc(sizeof(char) * i)))
		return ;
	controller->flags = flags;
}

int		sub_proc_getflags(t_contr *ctr, int *pos, int j, int p)
{
	char c;

	c = ctr->str_in[j + *pos];
	if (isin(c, "123456789*") && (ctr->flags->flags[p] = 'n'))
	{
		if (ctr->str_in[j + *pos] == '*' && ++(*pos))
		{
			ctr->flags->vals[p] = va_arg(*(ctr->args), int);
			if (ctr->flags->vals[p] < 0 && (ctr->flags->flags[p] = '-'))
				ctr->flags->vals[p] = ft_abs(ctr->flags->vals[p]);
		}
		else
			*pos = refresh(ctr, *pos, j, p);
		return (1);
	}
	else if (isin(ctr->str_in[j + *pos], "-0."))
	{
		ctr->flags->flags[p] = ctr->str_in[j + *pos];
		if (ctr->str_in[j + *pos + 1] == '*' && (*pos += 2))
			ctr->flags->vals[p] = va_arg(*(ctr->args), int);
		else if (++(*pos))
			*pos = refresh(ctr, *pos, j, p);
		return (1);
	}
	return (0);
}
