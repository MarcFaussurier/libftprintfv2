/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:47:33 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/25 12:39:44 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#define IMIN "9223372036854775808"

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
