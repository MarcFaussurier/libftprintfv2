/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cprintf2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:39:22 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/25 18:24:04 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int (*const g_specifiers[255])
	(t_lambda f, t_fmt_params p, va_list ap) = {
['c'] = fmt_c,
['i'] = fmt_i,
['d'] = fmt_i,
['u'] = fmt_u,
['o'] = fmt_o,
['O'] = fmt_o,
['x'] = fmt_x,
['X'] = fmt_x_up,
['s'] = fmt_s,
['p'] = fmt_p,
['%'] = fmt_percent
};

static void	parse_flags(const char **fmt, t_fmt_params *p, va_list ap)
{
	*p = (t_fmt_params){{0, 0, 0}, 0, 0, 0, 0, 0, -1, 0};
	while (1)
		if (**fmt == '+' && ++*fmt)
			p->plus = 1;
	else if (**fmt == '-' && ++*fmt)
		p->minus = 1;
	else if (**fmt == '0' && ++*fmt)
	{
		if (!p->minus)
			p->zero = 1;
	}
	else if (**fmt == ' ' && ++*fmt)
		p->blank = 1;
	else if (**fmt == '#' && ++*fmt)
		p->sharp = 1;
	else if (**fmt == '\'' && ++*fmt)
		(void)0;		
	else if (**fmt >= '0' && **fmt <= '9')
		p->padding = read_num(fmt, ap);
	else if (**fmt == '*')
		parse_star(fmt, p, ap);
	else if (**fmt == '.' && ++*fmt)
		p->precision = read_num(fmt, ap);
	else
		break ;
}

static void	parse_modifiers(const char **fmt, t_fmt_params *p)
{
	int	i;

	i = 0;
	while ((**fmt == 'h' || **fmt == 'l' || **fmt == 'L' || **fmt == 'z')
		&& i < 2)
	{
		p->modifiers[i++] = **fmt;
		*fmt += 1;
	}
	p->modifiers[i] = 0;
}

void	parse_star(const char **fmt, t_fmt_params *p, va_list ap)
{
	*fmt += 1;
	p->padding = va_arg(ap, int);
	if (p->padding < 0)
	{
		p->padding *= -1;
		p->minus = 1;
	}
}

int	parse_percent(t_lambda f, const char **fmt, va_list ap, int *r)
{
	t_fmt_params	p;
	int				*ptr;
	int				t;

	*fmt += 1;
	parse_flags(fmt, &p, ap);
	parse_modifiers(fmt, &p);
	if (**fmt == 'n')
	{
		ptr = (int *)(va_arg(ap, t_ull));
		if (ptr)
			*ptr = *r;
	}
	else if (g_specifiers[(unsigned char)**fmt])
	{	
		t = g_specifiers[(unsigned char)**fmt](f, p, ap);
		if (t < 0)
			return (t);
		*r += t;
	}
	else
		*r += ft_vcprintf(f, p.modifiers, ap)
			+ ((t_putchar) f.ptr)(**fmt, f.data);
	return (0);
}
