/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:50:16 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 15:53:11 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

int	fmt_s(t_lambda f, t_fmt_params p, va_list ap)
{
	int			r;
	char		*s;

	s = va_arg(ap, char *);
	if (!s)
		return (ft_cprintf(f, "(null)"));
	if (p.precision == -1)
		p.precision = ft_strlen(s);
	r = 0;
	if (!p.minus)
		while (p.padding && p.padding-- > p.precision)
		{
			r += (((t_putchar)f.ptr)(' ', f.data));
		}
	while (*s && (p.precision--))
	{
		r += (((t_putchar)f.ptr)(*s, f.data));
		s += 1;
		p.padding -= 1;
	}
	if (p.minus)
		while (((int)p.padding--) > 0)
		{
			r += (((t_putchar)f.ptr)(' ', f.data));
		}
	return (r);
}
