/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:54:42 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/25 13:02:28 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef unsigned long long	t_64;
typedef unsigned long long	t_ull;
typedef long long			t_ll;
typedef int					(*t_putchar)(char c, void *data);
typedef struct s_pcstr
{
	int			l:			32;
	const char	*s;
}	t_pcstr;
typedef struct s_pstr
{
	int			l:			32;
	char		*s;
}	t_pstr;
typedef struct s_num_pad
{
	t_pstr	num;
	t_pcstr	prefix;
	char	sign;
}	t_num_pad;
typedef struct s_lambda
{
	void		*ptr;
	void		*data;
}	t_lambda;
typedef struct s_fmt_params
{
	char		modifiers[3];
	char		zero:		1;
	char		plus:		1;
	char		minus:		1;
	char		blank:		1;
	char		sharp:		1;
	int			precision:	32;
	int			padding:	32;
}	t_fmt_params;
typedef enum e_type
{
	UC	= -1,
	US	= -2,
	U	= -4,
	UL	= -8,
	ULL	= UL,
	C	= 1,
	SI	= 2,
	I	= 4,
	LI	= 8,
	LLI	= LI,
}	t_type;
/**/
void	pstr_write(char c, t_pstr *num);
int		pad_num( t_lambda f, t_fmt_params p, t_num_pad s);
/**/
int		ft_printf(const char *fmt, ...);
int		ft_vprintf(const char *fmt, va_list ap);
int		ft_asprintf(char **s, const char *fmt, ...);
int		ft_vasprintf(char **s, const char *fmt, va_list ap);
/**/
int		ft_vcprintf(t_lambda f, const char *fmt, va_list ap);
int		ft_cprintf(t_lambda f, const char *fmt, ...);
/**/
int		ft_strlen(char *s);
int		ft_one(char c, void *data);
/**/
int		ft_citoa_base(t_lambda f, long long i, t_pcstr b);
int		ft_cutoa_base(t_lambda f, unsigned long long u, t_pcstr b);
/**/
t_type	ft_modifiers_to_type(char modifiers[2]);
t_type	ft_sign_type(t_type u);
t_64	va_arg64(t_type t, va_list ap);

/**/
int		fmt_i(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_u(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_x(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_x_up(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_o(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_p(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_percent(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_s(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_c(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_f(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_g(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_g_up(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_e(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_e_ip(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_a(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_a_up(t_lambda f, t_fmt_params p, va_list ap);
int		fmt_b(t_lambda f, t_fmt_params p, va_list ap);
/**/
int		pad_s(int a, t_lambda f, t_fmt_params p, char *s);
#endif
