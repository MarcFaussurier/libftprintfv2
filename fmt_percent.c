/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:55:06 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 15:57:25 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_percent(t_lambda f, t_fmt_params p, va_list ap)
{
	int			r;
	char		s[2];

	s[0] = '%';
	s[1] = 0;
	if (p.precision == -1)
		p.precision = ft_strlen(s);
	r = 0;
	if (!p.minus)
		while (p.padding && p.padding-- > p.precision)
		{
			r += (((t_putchar)f.ptr)(' ', f.data));
		}
		r += (((t_putchar)f.ptr)(s[0], f.data));
		p.padding -= 1;
	if (p.minus)
		while (((int)p.padding--) > 0)
		{
			r += (((t_putchar)f.ptr)(' ', f.data));
		}
	return (r);
}
