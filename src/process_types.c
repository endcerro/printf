/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 03:33:15 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 03:33:16 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_p(t_contr *controller)
{
	char			*out;
	char			*tmp;
	int				len;
	unsigned long	number;

	number = va_arg(*(controller->args), unsigned long);
	out = ft_ultoa(number);
	tmp = ft_convert_base(out, "0123456789", "0123456789abcdef");
	free(out);
	out = ft_strjoin("0x", tmp);
	free(tmp);
	out = applyflags(controller, out);
	len = ft_strlen(out);
	write(1, out, len);
	*(controller->len) += len;
	*(controller->pos) += 1;
	free(out);
}

void	process_x(t_contr *controller, char c)
{
	char			*out;
	char			*tmp;
	int				len;
	unsigned int	number;

	number = va_arg(*(controller->args), unsigned int);
	out = NULL;
	tmp = ft_ultoa((unsigned long)number);
	if (c == 'x')
		out = ft_convert_base(tmp, "0123456789", "0123456789abcdef");
	else
		out = ft_convert_base(tmp, "0123456789", "0123456789ABCDEF");
	free(tmp);
	out = applyflags(controller, out);
	len = ft_strlen(out);
	write(1, out, len);
	*(controller->len) += len;
	*(controller->pos) += 1;
	free(out);
}

void	process_u(t_contr *controller)
{
	int		len;
	char	*out;

	out = ft_ultoa(va_arg(*(controller->args), unsigned int));
	out = applyflags(controller, out);
	len = ft_strlen(out);
	write(1, out, len);
	*(controller->len) += len;
	*(controller->pos) += 1;
	free(out);
}

void	process_pr(t_contr *controller)
{
	char	*out;
	int		len;

	out = ft_strdup("%");
	out = applyflags(controller, out);
	len = ft_strlen(out);
	write(1, out, len);
	free(out);
	*(controller->len) += len;
	*(controller->pos) += 1;
}

void	process_c(t_contr *controller)
{
	char			*out;
	int				len;
	int				i;
	unsigned char	c[1];

	c[0] = va_arg(*(controller->args), int);
	i = 0;
	out = ft_strdup("c");
	out = applyflags(controller, out);
	len = ft_strlen(out);
	while (i < len)
	{
		if (out[i] == 'c')
			write(1, c, 1);
		else
			write(1, out + i, 1);
		i++;
	}
	free(out);
	*(controller->len) += len;
	*(controller->pos) += 1;
}
