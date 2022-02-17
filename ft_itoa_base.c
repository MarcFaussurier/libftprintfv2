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

int	ft_itoa_base(t_lambda f, long long i, const char *b, int l)
{
	int	r;

	r = 0;
	if (i == LLONG_MIN)
		return (ft_cprintf(f, "%s", IMIN));
	else if (i < 0)
		i *= -1;
	return (r + ft_utoa_base(f, i, b, l));
}

int	ft_utoa_base(t_lambda f, unsigned long long u, const char *b, int l)
{
	int		r;
	char	buffer[65];
	int		i;

	if (!u)
		return (((t_putchar)f.ptr)(b[0], f.data));
	r = 0;
	i = 0;
	while (u)
	{
		buffer[i] = b[u % l];
		i += 1;
		u /= l;
	}
	if (i)
		i -= 1;
	while (i >= 0)
		r += (((t_putchar)f.ptr)(buffer[i--], f.data));
	return (r);
}
