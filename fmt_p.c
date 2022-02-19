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

typedef struct s_pad
{
	t_ull	i;
	char	space;
}	t_pad;

static inline int pad_p(int a, t_lambda f, t_fmt_params p, t_pad s)
{
	int		r;

	r = 0;
	p.padding -= p.precision;
	if (!(p.zero || p.minus))
		while (p.padding-- > 0)
			r += (((t_putchar)f.ptr)(' ', f.data));
	p.padding -= 2;
	r += (((t_putchar)f.ptr)('0', f.data));
	r += (((t_putchar)f.ptr)('x', f.data));
	if (!p.minus)
		while (p.padding-- > 0)
			r += (((t_putchar)f.ptr)(s.space, f.data));
	while (a < p.precision--)
		r += (((t_putchar)f.ptr)('0', f.data));
	r += ft_cutoa_base(f, s.i, (t_pcstr){16, "0123456789abcdef"});
	while (p.padding-- > 0)
		r += (((t_putchar)f.ptr)(' ', f.data));
	return (r);
}

int	fmt_p(t_lambda f, t_fmt_params p, va_list ap)
{
	int			a;
	t_pad		s;

	s.i = va_arg(ap, t_ull); 
	a = ft_cutoa_base((t_lambda){&ft_one, 0}, s.i,
			(t_pcstr){16, "0123456789abcdef"});
	if  ((p.plus && p.precision != -1 ) || p.minus)
		p.zero = 0;
	if (p.padding < p.precision)
		p.padding = p.precision;
	if (a > p.precision)
		p.precision = a;
	if (p.zero)
		s.space = '0';
	else
		s.space = ' ';
	return (pad_p(a, f, p, s));	
}
