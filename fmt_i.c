/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:38:17 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/25 13:05:13 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				pad_num( t_lambda f, t_fmt_params p, t_num_pad s)
{
	char        sign;
	int         i;
	int         y;
	int	  		len;
	int			r;

	i = 0;
	y = 0;
	r = 0;
	if (p.precision < 0 && p.precision != -1)
		p.precision = -1;
	if (p.padding < 0)
	{
		p.padding = -p.padding;
		p.minus = 1;
	}
	if (p.precision == 0 && s.prefix.l == 1)
	{	p.padding -= 1; }
	if ((!p.precision) && s.num.s[0] == '0')
	{   s.num.s[0] = 0; s.num.l = 0; p.zero = 0; }
	if (p.minus || (p.precision != -1 && p.padding))
		p.zero = 0;
	len = s.num.l;
//	printf("sharp? %i prefix? %i precision? %i padding? %i len? %i num.l? %i\n", p.sharp, s.prefix.l, p.precision, p.padding, len, s.num.l);
	if (/*(!p.minus || g)*/  s.prefix.l == 1 && p.sharp)
	{
		if (s.num.s[0] == '0' && p.precision <= 1)
			s.prefix.l = 0;
		p.precision -= 1;
	}
	if (s.sign)
		p.padding -= 1;
	if (s.prefix.l && s.num.l && p.sharp)
		if ((s.num.l && s.num.s[0] != '0') || s.prefix.l == 1)
			p.padding -= s.prefix.l;
	if (p.precision == -1)
		p.precision = len;
	if ( (long long) len > p.precision)
		p.precision = len;
	p.padding -= p.precision;
	if (!(p.minus || p.zero))
		while (p.padding-- > 0)
			r += (((t_putchar)f.ptr)(' ', f.data));
	if (s.sign)
			r += (((t_putchar)f.ptr)(s.sign, f.data));
	if ((s.num.l && s.num.s[0] != '0') || s.prefix.l == 1)
	{
		y = 0;
		if (s.prefix.l && p.sharp)
			while (y < s.prefix.l)
				r += (((t_putchar)f.ptr)(s.prefix.s[y++], f.data));
	}
	if (!p.minus)
		while (p.padding-- > 0)
		{	if (p.zero)
				r += (((t_putchar)f.ptr)('0', f.data));
			else
				r += (((t_putchar)f.ptr)(' ', f.data));
		}
	if (s.num.l && !(s.prefix.l == 1 && p.precision == 1))
		while ((long long)len <  p.precision--)
			r += (((t_putchar)f.ptr)('0', f.data));
	y = 0;
	if (s.num.l)
		while (y < len)
			r += (((t_putchar)f.ptr)(s.num.s[y++], f.data));
	else 
		while (y < len)
	r += (((t_putchar)f.ptr)(' ', f.data));
	while(p.padding-- > 0)
		r += (((t_putchar)f.ptr)(' ', f.data));
	return (r);
}

void	pstr_write(char c, t_pstr *num)
{
	num->s[num->l++] = c;
}

int	fmt_i(t_lambda f, t_fmt_params p, va_list ap)
{
	char		sign;
	char		b[64];
	t_pstr		num;
	t_ll		i;

	i = va_arg64(ft_sign_type(ft_modifiers_to_type(p.modifiers)), ap);
	num = (t_pstr) {.l=0, .s=&b[0]};
	ft_citoa_base((t_lambda){&pstr_write, &num}, i, (t_pcstr){10, "0123456789"});
	sign = 0;
	if (i < 0)
		sign = '-';
	else if (p.plus)
		sign = '+';
	else if (p.blank)
		sign = ' ';
	return (pad_num(f, p, (t_num_pad)
				{
				.num = (t_pstr) {.l=num.l, .s=num.s},
				.prefix =  (t_pcstr) {.l=0, .s=0},
				.sign = sign,
				}));
}
