/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:38:17 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 17:02:47 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct s_pad
{
	t_ll	i;
	char	sign;
	char	space;
	int		no_precision;
}	t_pad;

static inline int	pad_i(int a, t_lambda f, t_fmt_params p, t_pad s)
{
	int		r;
	int		d;


	r = 0;
	d = 0;
	if (p.padding > 0)
		d = 1;
	p.padding -= p.precision;
	if (!p.minus && !p.zero)
		while (p.padding-- > 0)
			r += (((t_putchar)f.ptr)(' ', f.data));
	if (s.sign)
		r += (((t_putchar)f.ptr)(s.sign, f.data));
	if (!p.minus)
		while (p.padding-- > 0)
			r += (((t_putchar)f.ptr)(s.space, f.data));
//	if (p.zero)
		while (a < p.precision--)
			r += (((t_putchar)f.ptr)('0', f.data));
	if (!(!s.i && s.no_precision))// || (p.zero && d))
		r += ft_citoa_base(f, s.i, (t_pcstr){10, "0123456789"});
	else if (d)
		r += (((t_putchar)f.ptr)(' ', f.data));
	while (p.padding-- > 0)
		r += (((t_putchar)f.ptr)(' ', f.data));
	return (r);
}

int	fmt_i(t_lambda f, t_fmt_params p, va_list ap)
{
	int			a;
	t_pad		s;

	s.sign = 0;
	s.i = va_arg64(ft_sign_type(ft_modifiers_to_type(p.modifiers)), ap);
	a = ft_citoa_base((t_lambda){&ft_one, 0}, s.i,
			(t_pcstr){10, "0123456789"});

	if (p.minus)
		p.zero = 0;

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
	if (s.i < 0 && (p.padding-- || 1))
		s.sign = '-';
	else if (p.plus && (p.padding-- || 1))
		s.sign = '+';
	else if (p.blank && (p.padding-- || 1))
		s.sign = ' ';
	return (pad_i(a, f, p, s));
}
