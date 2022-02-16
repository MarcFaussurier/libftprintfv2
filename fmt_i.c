/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:38:17 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 17:02:47 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_i(t_lambda f, t_fmt_params p, va_list ap)
{
	int			r;
	long long	i;
	char		*s;

	r = 0;
	i = va_arg(ap, long long);
	if (p.modifiers[0] == 'h' && p.modifiers[1] == 'h' && !p.modifiers[2])
		i = (char) i;
	else if (p.modifiers[0] == 'h' && !p.modifiers[1])
		i = (short int) i;
	else if (!p.modifiers[0])
		i = (int) i;
	else if (p.modifiers[0] == 'l' && !p.modifiers[1])
		i = (long) i;
	if (p.plus && i >= 0)
		r += ((t_putchar) f.ptr)('+', f.data);
	return (r + ft_itoa_base(f, i, "0123456789", 10));
}
