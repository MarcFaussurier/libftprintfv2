/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:47:33 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 16:26:43 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

long long	parse_i(t_fmt_params p, va_list ap)
{
	long long	i;

	i = va_arg(ap, long long);
	if (p.modifiers[0] == 'h' && p.modifiers[1] == 'h' && !p.modifiers[2])
		i = (char) i;
	else if (p.modifiers[0] == 'h' && !p.modifiers[1])
		i = (short int) i;
	else if (!p.modifiers[0])
		i = (int) i;
	else if (p.modifiers[0] == 'l' && !p.modifiers[1])
		i = (long) i;
	return (i);
}

unsigned long long	parse_u(t_fmt_params p, va_list ap)
{
	unsigned long long	i;

	i = va_arg(ap, unsigned long long);
	if (p.modifiers[0] == 'h' && p.modifiers[1] == 'h' && !p.modifiers[2])
		i = (unsigned char) i;
	else if (p.modifiers[0] == 'h' && !p.modifiers[1])
		i = (unsigned short int) i;
	else if (!p.modifiers[0])
		i = (unsigned int) i;
	else if (p.modifiers[0] == 'l' && !p.modifiers[1])
		i = (unsigned long) i;
	return (i);
}

int	ft_citoa_base(t_lambda f, t_ll i, t_pcstr b)
{
	int	r;

	r = 0;
	if (i == LLONG_MIN)
		return (ft_cprintf(f, "%s", IMIN));
	else if (i < 0)
		i *= -1;
	return (r + ft_cutoa_base(f, i, b));
}

int	ft_cutoa_base(t_lambda f, t_ull u, t_pcstr b)
{
	int		r;
	char	buffer[65];
	int		i;

	if (!u)
		return (((t_putchar)f.ptr)(b.s[0], f.data));
	r = 0;
	i = 0;
	while (u)
	{
		buffer[i] = b.s[u % b.l];
		i += 1;
		u /= b.l;
	}
	if (i)
		i -= 1;
	while (i >= 0)
		r += (((t_putchar)f.ptr)(buffer[i--], f.data));
	return (r);
}
