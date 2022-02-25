/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:55:06 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/25 13:21:18 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_percent(t_lambda f, t_fmt_params p, va_list ap)
{
	int		r;

	(void) ap;
	//c = va_arg(ap, int);
	r = 0;
	if (!(p.minus))
			while (--p.padding > 0)
			{
				if (p.zero)
					r += (((t_putchar)f.ptr)('0', f.data));
				else
					r += (((t_putchar)f.ptr)(' ', f.data));
			}
	r += (((t_putchar)f.ptr)('%', f.data));
	while (--p.padding > 0)
		r += (((t_putchar)f.ptr)(' ', f.data));
	return (r);
}
