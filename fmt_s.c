/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:50:16 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/25 18:25:19 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define E

int	pad_s(int a, t_lambda f, t_fmt_params p, char *s)
{
	int		r;
	char	space;

	r = 0;
	if (p.zero)
		space = '0';
	else
		space = ' ';
	if (p.precision < 0)
		p.precision = a;
	if (p.precision > a)
		p.precision = a;
	if (!p.minus)
		while (p.padding && p.padding-- > p.precision)
			r += (((t_putchar)f.ptr)(space, f.data));
	while (*s && (p.precision--))
	{
		r += (((t_putchar)f.ptr)(*s, f.data));
		s += 1;
		p.padding -= 1;
	}
	while (((int)p.padding--) > 0)
		r += (((t_putchar)f.ptr)(' ', f.data));
	return (r);
}

int	fmt_s(t_lambda f, t_fmt_params p, va_list ap)
{
	char		*s;
	int			a;
	int			k;
	int			prec;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	a = ft_strlen(s);
	if (p.modifiers[0] == 'l' && !p.modifiers[1])
	{
		if ((p.precision == -1) || p.precision > a)
			prec = a;
		else
			prec = p.precision;
		k = 0;
		while (s[k] && (prec))
		{
			if (s[k] < 0)
				((int (*)(char E, void *))f.ptr)(0, f.data);
			return (-1);
		}
	}
	return (pad_s(a, f, p, s));
}
