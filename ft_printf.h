/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:54:42 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 14:08:34 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef unsigned long long ull;
typedef int	(*t_putchar)(char c, void *data);
typedef struct s_lambda
{
	void	*ptr;
	void	*data;
}	t_lambda;
typedef struct s_fmt_params
{
	char	modifiers[3];
	ull		zero:		1;
	ull		plus:		1;
	ull		minus:		1;
	ull		blank:		1;
	ull		sharp:		1;
	ull		precision:  32;
	ull		padding:	32;
}	t_fmt_params;

int	ft_vprintf(const char *fmt, va_list ap);
int	ft_printf(const char *fmt, ...);
int	ft_vcprintf(t_lambda f, const char *fmt, va_list ap);
int	ft_cprintf(t_lambda f, const char *fmt, ...);

int fmt_i(t_lambda f, t_fmt_params p, va_list ap);
int fmt_u(t_lambda f, t_fmt_params p, va_list ap);
int fmt_x(t_lambda f, t_fmt_params p, va_list ap);
int fmt_x_up(t_lambda f, t_fmt_params p, va_list ap);
int fmt_o(t_lambda f, t_fmt_params p, va_list ap);
int fmt_p(t_lambda f, t_fmt_params p, va_list ap);
int fmt_percent(t_lambda f, t_fmt_params p, va_list ap);
int fmt_s(t_lambda f, t_fmt_params p, va_list ap);
int fmt_c(t_lambda f, t_fmt_params p, va_list ap);

int fmt_f(t_lambda f, t_fmt_params p, va_list ap);

int fmt_g(t_lambda f, t_fmt_params p, va_list ap);
int fmt_g_up(t_lambda f, t_fmt_params p, va_list ap);
int fmt_e(t_lambda f, t_fmt_params p, va_list ap);
int fmt_e_ip(t_lambda f, t_fmt_params p, va_list ap);

int fmt_a(t_lambda f, t_fmt_params p, va_list ap);
int fmt_a_up(t_lambda f, t_fmt_params p, va_list ap);

int fmt_b(t_lambda f, t_fmt_params p, va_list ap);
#endif