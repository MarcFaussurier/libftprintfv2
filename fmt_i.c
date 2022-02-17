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
#include <limits.h>



int	fmt_i(t_lambda f, t_fmt_params p, va_list ap)
{
	int			r;
	long long	i;
	char		*s;
	int			el;
	int			z;
	char		c;
	char 		sign;

	i = va_arg(ap, long long);
	if (p.modifiers[0] == 'h' && p.modifiers[1] == 'h' && !p.modifiers[2])
		i = (char) i;
	else if (p.modifiers[0] == 'h' && !p.modifiers[1])
		i = (short int) i;
	else if (!p.modifiers[0])
		i = (int) i;
	else if (p.modifiers[0] == 'l' && !p.modifiers[1])
		i = (long) i;
	el = ft_itoa_base((t_lambda){&ft_countc, 0}, i, "0123456789", 10);
	if  ((p.plus && p.precision != -1 ) || p.minus)
		p.zero = 0;
	if (p.padding < p.precision)
		p.padding = p.precision;
	c = p.zero ? '0' : ' ';
	sign = 0;
	if (i < 0) 
	{
		sign = '-';
		p.padding -= 1;
	}
	else if (p.plus) {
		sign = '+';
		p.padding -= 1;
	}
	else if (p.blank) 
	{
		sign = ' ';
		p.padding -= 1;
	}
	if (el > p.precision)
		p.precision = el;
	p.padding -= p.precision;
	r = 0;
	if (!(p.zero || p.minus))
		while (p.padding-- > 0)
			r += (((t_putchar)f.ptr)(' ', f.data));
	if (sign)
		r += (((t_putchar)f.ptr)(sign, f.data));
	if (!p.minus)
		while (p.padding-- > 0)
			r += (((t_putchar)f.ptr)(c, f.data));
	while (el < p.precision--)
		r += (((t_putchar)f.ptr)('0', f.data));
	r += ft_itoa_base(f, i, "0123456789", 10);
	while (p.padding-- > 0)
		r += (((t_putchar)f.ptr)(' ', f.data));
	return (r);
}
