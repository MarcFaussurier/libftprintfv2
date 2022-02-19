/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:43:22 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 17:16:57 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

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

static int	read_num(const char **fmt, va_list ap)
{
	int	i;

	i = 0;
	if (**fmt == '*')
		return (va_arg(ap, int));
	while (**fmt >= '0' && **fmt <= '9')
	{
		i *= 10;
		i += **fmt - '0';
		*fmt += 1;
	}
	return (i);
}

static void	parse_flags(const char **fmt, t_fmt_params *p, va_list ap)
{
	*p = (t_fmt_params){{0, 0, 0}, 0, 0, 0, 0, 0, -1, -1};
	while (1)
		if (**fmt == '+' && ++*fmt)
			p->plus = 1;
	else if (**fmt == '-' && ++*fmt)
		p->minus = 1;
	else if (**fmt == '0' && ++*fmt)
		p->zero = 1;
	else if (**fmt == ' ' && ++*fmt)
		p->blank = 1;
	else if (**fmt == '#' && ++*fmt)
		p->sharp = 1;
	else if (**fmt >= '0' && **fmt <= '9')
		p->padding = read_num(fmt, ap);
	else if (**fmt == '*' && ++fmt)
		p->padding = va_arg(ap, int);
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

int	ft_vcprintf(t_lambda f, const char *fmt, va_list ap)
{
	t_fmt_params	p;
	int				r;
	int				*ptr;

	r = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt += 1;
			parse_flags(&fmt, &p, ap);
			parse_modifiers(&fmt, &p);
			if (*fmt == 'n')
			{
				ptr = (int*)(va_arg(ap, t_ull));
				if (ptr)
					*ptr = r;
			}
			else if (g_specifiers[*fmt])
				r += g_specifiers[*fmt](f, p, ap);
			else
				r += ft_vcprintf(f, p.modifiers, ap)
					+ ((t_putchar) f.ptr)(*fmt, f.data);
		}
		else
			r += ((t_putchar) f.ptr)(*fmt, f.data);
		fmt += 1;
	}
	return (r);
}

int	ft_cprintf(t_lambda f, const char *fmt, ...)
{
	va_list	ap;
	int		r;

	va_start(ap, fmt);
	r = ft_vcprintf(f, fmt, ap);
	va_end(ap);
	return (r);
}
