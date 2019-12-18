/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:25:23 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/18 21:25:24 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

# include <unistd.h>

# include <stdarg.h>

# include <stdio.h>

# include "../libft/libft.h"

typedef struct		s_contr
{
	int				*len;
	int				*pos;
	va_list			*args;
	char			*str_in;
}					t_contr;

int					ft_printf(const char *str_in, ...);
char				*ft_ultoa(unsigned long n);
unsigned char		*process_0(t_contr *controller);
unsigned char		*process_type(t_contr *controller);
unsigned char		*process_dot(t_contr *controller);
unsigned char		*process_minus(t_contr *controller);
unsigned char		*process_nb(t_contr *controller);
unsigned char		*process(t_contr *controller);
unsigned char		*process_flag(t_contr *controller);
unsigned char		*process_star(t_contr *controller);
unsigned char		*process_s(t_contr *controller);
unsigned char		*process_p(t_contr *controller);
unsigned char		*process_x(t_contr *controller, char x);
void				sub_process0(int nb, unsigned char **output, char c);
unsigned char		*append_char(unsigned char *b, char t, int c, int o);
void				ft_putustr(unsigned char *in);
int					ft_ustrlen(unsigned char *str);
unsigned char		*ft_ustrdup(unsigned char *s1);
unsigned char		*ft_ustrjoin(unsigned char *s1, unsigned char *z);
unsigned char		*ft_usubstr(unsigned char *s, unsigned int st, size_t l);
unsigned char		*sub_sub_dot(unsigned char *ot, unsigned char *zr);
unsigned char		*sub_process_dot(unsigned char *output, int nb);
#endif
