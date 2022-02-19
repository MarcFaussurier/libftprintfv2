/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:55:06 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 15:58:12 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pad_c(t_lambda f, t_fmt_params p, char c)
{
	int		r;
	char	space;

	r = 0;
	if (p.zero)
		space = '0';
	else
		space = ' ';
	if (p.precision == -1)
		p.precision = 1;
	if (!p.minus)
		while (p.padding && p.padding-- > p.precision)
			r += (((t_putchar)f.ptr)(space, f.data));
	r += (((t_putchar)f.ptr)(c, f.data));
	p.precision -= 1;
	p.padding -= 1;
	while (((int)p.padding--) > 0)
		r += (((t_putchar)f.ptr)(' ', f.data));
	return (r);
}

int	fmt_c(t_lambda f, t_fmt_params p, va_list ap)
{
	int	i;

	i = va_arg(ap, int);
	if (p.modifiers[0] == 'l' && !p.modifiers[1] && (i < 0 || i > 255))
	{
		((int(*)(char, void*))f.ptr)(0, f.data);
		return (-1);
	}
	return (pad_c(f, p, i));
}
