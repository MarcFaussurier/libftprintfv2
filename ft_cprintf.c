/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:43:22 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 14:21:39 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

#include <stdio.h>

int	fmt_i(t_lambda f, t_fmt_params p, va_list ap)
{
	long long	i;
	char		*s;

	i = va_arg(ap, long long);
	if (p.modifiers[0] == 'h' && p.modifiers[1] == 'h' && !p.modifiers[2])
		i = (char) i;
	else if (p.modifiers[0] == 'h' && !p.modifiers[1])
		i = (short int) i;
	else if (!p.modifiers[0] && !p.modifiers[1])
		i = (int) i;
	else if (p.modifiers[0] == 'l' && !p.modifiers[1])
		i = (long) i;
	asprintf(&s, "%lli", i);
	while (*s)
	{
		((t_putchar)f.ptr)(*s, f.data);
		s += 1;
	}
	return (0);
}

static
int (*const g_specifiers[255])
	(t_lambda f, t_fmt_params p, va_list ap) = {
	['i'] = fmt_i,
	['d'] = fmt_i
};

static int	read_num(const char **fmt)
{
	int	i;

	i = 0;
	while (**fmt >= '0' && **fmt <= '9')
	{
		i *= 10;
		i += **fmt - '0';
		*fmt += 1;
	}
	return (i);
}

static void parse_flags(const char **fmt, t_fmt_params *p, va_list ap)
{
	while (1)
	{
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
		else if (**fmt == '.' && ++*fmt && **fmt != '*')
			p->precision = read_num(fmt);
		else if (**fmt == '.' && ++*fmt)
			p->precision = va_arg(ap, int);
		else if (**fmt >= '0' && **fmt <= '9')
			p->padding = read_num(fmt);
		else if (**fmt == '*' && ++fmt)
			p->padding = va_arg(ap, int);
		else
			break ;
	}
}

static void parse_modifiers(const char **fmt, t_fmt_params *p)
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

	r = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt += 1;
			parse_flags(&fmt, &p, ap);
			parse_modifiers(&fmt, &p);
			if (*fmt == 'n')
				r += ft_cprintf(f, "%i", r);
			else if (g_specifiers[*fmt])
				r += g_specifiers[*fmt](f, p, ap);
			else
				r += ft_vcprintf(f, p.modifiers, ap) + ((t_putchar) f.ptr)(*fmt,  f.data);
		}
		else
			r += ((t_putchar) f.ptr)(*fmt, f.data);
		fmt += 1;
	}
	return (0);
}

int	ft_cprintf(t_lambda f, const char *fmt, ...)
{
	va_list	ap;
	int		r;

	va_start(ap, fmt);
	r = ft_vcprintf(f, fmt, ap);
	va_end(ap);
	return (0);
}

int	main(int ac, char **av)
{
	ft_printf("args:\n");
	ft_printf("%hhi %p\n", 42);
	while (ac)
	{
		ft_printf(av[--ac]);
		ft_printf("\n");
	}
	return (0);
}
