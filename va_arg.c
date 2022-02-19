/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:27:46 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/19 16:55:51 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	ft_modifiers_to_type(char modifiers[2])
{
	if (modifiers[0] == 'h' && modifiers[1] == 'h')
		return (UC);
	if (modifiers[0] == 'h' && !modifiers[1])
		return (US);
	if (!modifiers[0])
		return (U);
	if ((modifiers[0] == 'l' && !modifiers[1])
		|| modifiers[0] == 'z')
		return (UL);
	if (modifiers[0] == 'l' && modifiers[1] == 'l')
		return (ULL);
	return (U);
}

t_type	ft_sign_type(t_type u)
{
	if (u < 0)
		return (u * -1);
	return (u);
}

t_64	va_arg64(t_type t, va_list ap)
{
	if (t == UC)
		return ((t_64)(unsigned char) va_arg(ap, unsigned int));
	if (t == US)
		return ((t_64)(unsigned short) va_arg(ap, unsigned int));
	if (t == U)
		return ((t_64)(unsigned int) va_arg(ap, unsigned int));
	if (t == UL)
		return ((t_64)(unsigned long) va_arg(ap, unsigned long));
	if (t == C)
		return ((t_64)(char) va_arg(ap, int));
	if (t == SI)
		return ((t_64)(short) va_arg(ap, int));
	if (t == I)
		return ((t_64)(int) va_arg(ap, int));
	if (t == LI)
		return ((long) va_arg(ap, long));
	return ((t_64) va_arg(ap, t_ll));
}
