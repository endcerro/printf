/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:30:37 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/18 18:30:38 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*process_s(c_contr *controller)
{
	unsigned char	*tmp;

	tmp = va_arg(*(controller->args), unsigned char*);
	if (tmp == NULL)
		return (ft_ustrdup((unsigned char *)"(null)"));
	return (ft_ustrdup(tmp));
}

unsigned char	*process_p(c_contr *controller)
{
	char			*output;
	char			*tmp;
	unsigned char	*outuns;

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
	char			*tmp;
	unsigned char	*output;

	tmp = ft_ultoa((unsigned long)va_arg(*(controller->args), unsigned int));
	if (x == 'x')
		output = (unsigned char *)ft_convert_base(tmp, "0123456789",
		"0123456789abcdef");
	else
		output = (unsigned char *)ft_convert_base(tmp, "0123456789",
		"0123456789ABCDEF");
	free(tmp);
	return (output);
}

void			sub_process0(int nb, unsigned char **output, char c)
{
	if (nb < 0 && ((int)ft_ustrlen(*output) < ft_abs(nb)))
		*output = append_char(*output, ' ', ft_abs(nb), 0);
	else if (*output[0] == '-' && (int)ft_ustrlen(*output) < nb)
	{
		*output[0] = '0';
		*output = append_char(*output, c, nb, 1);
		*output[0] = '-';
	}
	else
		*output = append_char(*output, c, nb, 1);
}
