/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:55:06 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/25 15:25:19 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#define E

int	fmt_c(t_lambda f, t_fmt_params p, va_list ap)
{
	int		r;
	int		c;

	c = va_arg(ap, int);
	if (p.modifiers[0] == 'l' && !p.modifiers[1] && (c < 0 || c > 255))
	{
		((int (*)(char E, void *))f.ptr)(0, f.data);
		return (-1);
	}
	r = 0;
	if (!(p.minus))
	{
		while (--p.padding > 0)
			if (p.zero)
				r += (((t_putchar)f.ptr)('0', f.data));
		else
			r += (((t_putchar)f.ptr)(' ', f.data));
	}
	r += (((t_putchar)f.ptr)((unsigned char)c, f.data));
	while (--p.padding > 0)
		r += (((t_putchar)f.ptr)(' ', f.data));
	return (r);
}
