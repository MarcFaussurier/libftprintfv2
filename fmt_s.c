/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:50:16 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/25 13:22:08 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int			pad;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";

	if (p.modifiers[0] == 'l' && !p.modifiers[1])
	{
		pad = p.padding;
		if (p.precision == -1)
			prec = a;
		if (p.precision > a)
			prec = a;
		if (!p.minus)
			while (pad && pad-- > prec)
				;
		k = 0;
		while (s[k] && (prec))
		{
			if ((s[k] < 0 || s[k] > 255))
				((int(*)(char, void*))f.ptr)(0, f.data);
			return (-1);
		}
	}
	a = ft_strlen(s);
	return (pad_s(a, f, p, s));
}
