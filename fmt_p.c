/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:53:15 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 16:47:44 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_p(t_lambda f, t_fmt_params p, va_list ap)
{
  	unsigned long long 	i;
	int					r;
	char				*s;
	int					el;
	int					z;
	char				c;
	char 				sign;

	i = va_arg(ap, unsigned long long);
	el = ft_utoa_base((t_lambda){&ft_countc, 0}, i, "0123456789abcdef", 16);
	if  ((p.plus && p.precision != -1 ) || p.minus)
		p.zero = 0;
	if (p.padding < p.precision)
		p.padding = p.precision;
	c = p.zero ? '0' : ' ';
	if (el > p.precision)
		p.precision = el;
	p.padding -= p.precision;
	r = 0;
	if (!(p.zero || p.minus))
		while (p.padding-- > 0)
			r += (((t_putchar)f.ptr)(' ', f.data));
	
	r += (((t_putchar)f.ptr)('0', f.data)) + 
		(((t_putchar)f.ptr)('x', f.data));
	p.padding -= 2;

	if (!p.minus)
		while (p.padding-- > 0)
			r += (((t_putchar)f.ptr)(c, f.data));
	while (el < p.precision--)
		r += (((t_putchar)f.ptr)('0', f.data));
	r += ft_utoa_base(f, i, "0123456789abcdef", 16);
	while (p.padding-- > 0)
		r += (((t_putchar)f.ptr)(' ', f.data));
	return (r);
}
