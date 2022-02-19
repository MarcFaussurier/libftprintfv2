/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:50:16 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 15:53:11 by mafaussu         ###   ########lyon.fr   */
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
	if (p.precision == -1)
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

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	a = ft_strlen(s);
	return (pad_s(a, f, p, s));
}
