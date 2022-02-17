/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:42:54 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 17:04:35 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_o(t_lambda f, t_fmt_params p, va_list ap)
{
	int					r;
	unsigned long long	i;
	char				*s;
	int					el;
	int					z;
	char				c;
	char				sign;

	i = parse_u(p, ap);
	el = ft_utoa_base((t_lambda){&ft_countc, 0}, i, "01234567", 8);
	if ((p.plus && p.precision != -1) || p.minus)
		p.zero = 0;
	if (p.padding < p.precision)
		p.padding = p.precision;
	if (p.zero)
		c = '0';
	else
		c = ' ';
	sign = 0;
	if (p.plus)
	{
		sign = '+';
		p.padding -= 1;
	}
	else if (p.blank)
	{
		sign = ' ';
		p.padding -= 1;
	}
	if (p.sharp && i)
		p.padding -= 1;
	if (el > p.precision)
		p.precision = el;
	p.padding -= p.precision;
	r = 0;
	if (!(p.zero || p.minus))
		while (p.padding-- > 0)
			r += (((t_putchar)f.ptr)(' ', f.data));
	if (p.sharp && i)
		r += ((t_putchar) f.ptr)('0', f.data);
	if (sign)
		r += (((t_putchar)f.ptr)(sign, f.data));
	if (!p.minus)
		while (p.padding-- > 0)
			r += (((t_putchar)f.ptr)(c, f.data));
	while (el < p.precision--)
		r += (((t_putchar)f.ptr)('0', f.data));
	r += ft_utoa_base(f, i, "01234567", 8);
	while (p.padding-- > 0)
		r += (((t_putchar)f.ptr)(' ', f.data));
	return (r);
}
