/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:38:17 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 15:49:42 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_i(t_lambda f, t_fmt_params p, va_list ap)
{
	long long	i;
	char		*s;

	i = va_arg(ap, long long);
	if (p.modifiers[0] == 'h' && p.modifiers[1] == 'h' && !p.modifiers[2])
		i = (char) i;
	else if (p.modifiers[0] == 'h' && !p.modifiers[1])
		i = (short int) i;
	else if (!p.modifiers[0] && !p.modifiers[1])
		i = (int) i;
	else if (p.modifiers[0] == 'l' && !p.modifiers[1])
		i = (long) i;
	return (ft_itoa_base(f, i, "0123456789", 10));
}
