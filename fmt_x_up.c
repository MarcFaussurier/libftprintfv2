/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:46:33 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 17:05:53 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_x_up(t_lambda f, t_fmt_params p, va_list ap)
{
	int					r;
	unsigned long long	i;
	char				*s;

	r = 0;
	i = va_arg(ap, unsigned long long);
	if (p.modifiers[0] == 'h' && p.modifiers[1] == 'h' && !p.modifiers[2])
		i = (unsigned char) i;
	else if (p.modifiers[0] == 'h' && !p.modifiers[1])
		i = (unsigned short int) i;
	else if (!p.modifiers[0])
		i = (unsigned int) i;
	else if (p.modifiers[0] == 'l' && !p.modifiers[1])
		i = (unsigned long) i;
	if (p.sharp)
		r += ((t_putchar) f.ptr)('0', f.data) + 
			((t_putchar) f.ptr)('X', f.data);
	return (r + ft_utoa_base(f, i, "0123456789ABCDEF", 16));
}
