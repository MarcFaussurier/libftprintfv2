/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:54:42 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 15:44:30 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# define IMIN "-9223372036854775808"


typedef unsigned long long	t_ull;
typedef int					(*t_putchar)(char c, void *data);
typedef struct s_lambda
{
	void	*ptr;
	void	*data;
}	t_lambda;
typedef struct s_fmt_params
{
	char	modifiers[3];
	t_ull	zero:		1;
	t_ull	plus:		1;
	t_ull	minus:		1;
	t_ull	blank:		1;
	t_ull	sharp:		1;
	int		precision:	32;
	int		padding:	32;
}	t_fmt_params;
int	ft_vprintf(const char *fmt, va_list ap);
int	ft_printf(const char *fmt, ...);
int	ft_vcprintf(t_lambda f, const char *fmt, va_list ap);
int	ft_cprintf(t_lambda f, const char *fmt, ...);
int	ft_itoa_base(t_lambda f, long long i, const char *b, int l);
int	ft_utoa_base(t_lambda f, unsigned long long u, const char *b, int l);
int	fmt_i(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_u(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_x(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_x_up(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_o(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_p(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_percent(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_s(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_c(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_f(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_g(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_g_up(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_e(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_e_ip(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_a(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_a_up(t_lambda f, t_fmt_params p, va_list ap);
int	fmt_b(t_lambda f, t_fmt_params p, va_list ap);
int	ft_strlen(char *s);
int ft_countc(char c, void *data);
long long	parse_i(t_fmt_params p, va_list ap);
unsigned long long	parse_u(t_fmt_params p, va_list ap);
#endif
