/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:46:33 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 17:06:34 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct s_pad
{
	t_ull	i;
	char	space;
	int		up;
	int		no_precision;
	t_pcstr	b;
}	t_pad;

static inline int	pad_x(int a, t_lambda f, t_fmt_params p, t_pad s)
{
	int		r;
	int		d;

	r = 0;
	d = 0;
	if (p.padding > 0)
		d = 1;

	if (p.sharp && s.i)
	{
		p.padding -= 2;
	}
	
	p.padding -= p.precision;
	if (!p.minus && !p.zero)
		while (p.padding-- > 0)
			r += (((t_putchar)f.ptr)(' ', f.data));
	if (p.sharp && s.i)
	{
		r += (((t_putchar)f.ptr)('0', f.data));
		if (s.up)
			r += (((t_putchar)f.ptr)('X', f.data));
		else
			r += (((t_putchar)f.ptr)('x', f.data));
	}
	if (!p.minus)
		while (p.padding-- > 0)
			r += (((t_putchar)f.ptr)(s.space, f.data));
//	if (p.zero)
		while (a < p.precision--)
			r += (((t_putchar)f.ptr)('0', f.data));
	if (!(!s.i && s.no_precision) /*|| p.sharp*/)
		r += ft_cutoa_base(f, s.i, s.b);
	else if (d)
		r += (((t_putchar)f.ptr)(' ', f.data));
	while (p.padding-- > 0)
		r += (((t_putchar)f.ptr)(' ', f.data));
	return (r);
}

static inline int	generic_fmt_x(t_lambda f, t_fmt_params p,
		va_list ap, int up)
{
	int			a;
	t_pad		s;

	if (up)
		s.b = (t_pcstr){16, "0123456789ABCDEF"};
	else
		s.b = (t_pcstr){16, "0123456789abcdef"};
	s.i = va_arg64(ft_modifiers_to_type(p.modifiers), ap);
	a = ft_cutoa_base((t_lambda){&ft_one, 0}, s.i, s.b);
	if (p.precision == 0)
	{
		p.zero = 0;
		s.no_precision = 1;
	}
	else
		s.no_precision = 0;
//	if ((p.plus && p.precision != -1) || p.minus)
//		p.zero = 0;
	if (p.padding < p.precision)
		p.padding = p.precision;
	if (a > p.precision)
		p.precision = a;
	if (p.zero)
		s.space = '0';
	else
		s.space = ' ';
	s.up = up;
	return (pad_x(a, f, p, s));
}

int	fmt_x(t_lambda f, t_fmt_params p, va_list ap)
{
	return (generic_fmt_x(f, p, ap, 0));
}

int	fmt_x_up(t_lambda f, t_fmt_params p, va_list ap)
{
	return (generic_fmt_x(f, p, ap, 1));
}
