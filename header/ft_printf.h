/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:25:23 by edal--ce          #+#    #+#             */
/*   Updated: 2019/12/28 08:16:40 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

# include <unistd.h>

# include <stdarg.h>

# include <stdio.h>

# include "../libft/libft.h"

typedef struct		s_flags
{
	char			*flags;
	int				*vals;
	int				nbfl;
}					t_flags;

typedef struct		s_contr
{
	int				*len;
	int				*pos;
	va_list			*args;
	char			*str_in;
	t_flags			*flags;
}					t_contr;

int					ft_printf(const char *str_in, ...);
char				*ft_ultoa(unsigned long n);

void				process_di(t_contr *controller);
void				process_s(t_contr *controller);
void				process_p(t_contr *controller);
void				process_x(t_contr *controller, char c);
void				process_u(t_contr *controller);
void				process_pr(t_contr *controller);
void				process_c(t_contr *controller);

int					sub_proc_getflags(t_contr *ctr, int *pos, int j, int p);
void				get_flag_contr(t_contr *controller, int i);

char				*process_0(t_contr *controller, int p, int val, char *in);
char				*process_dot(t_contr *controer, int p, int val, char *in);
int					refresh(t_contr *controller, int pos, int j, int p);
int					getmaxflags(t_contr *controller);
char				*applyflags(t_contr *controller, char *in);
char				*add_fill(char *base, char fill, int cpt, int order);
char				*add_fill_0(char *base, char fill, int cpt, int order);
char				*add_fill_hex(char *base, char fill, int cpt, int order);
int					isin(char c, char *str);

#endif
