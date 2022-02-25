/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:43:22 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/25 18:23:32 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

int	read_num(const char **fmt, va_list ap)
{
	int	i;

	i = 0;
	if (**fmt == '*')
	{
		*fmt += 1;
		i = va_arg(ap, int);
		return (i);
	}
	while (**fmt >= '0' && **fmt <= '9')
	{
		i *= 10;
		i += **fmt - '0';
		*fmt += 1;
	}
	return (i);
}

int	ft_vcprintf(t_lambda f, const char *fmt, va_list ap)
{
	int				r;
	int				t;

	r = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			t = parse_percent(f, &fmt, ap, &r);
			if (t != 0)
				return (t);
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
