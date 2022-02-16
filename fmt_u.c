/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:27:46 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 16:55:51 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_u(t_lambda f, t_fmt_params p, va_list ap)
{
	unsigned long long	i;
	char				*s;

	i = va_arg(ap, unsigned long long);
	if (p.modifiers[0] == 'h' && p.modifiers[1] == 'h' && !p.modifiers[2])
		i = (unsigned char) i;
	else if (p.modifiers[0] == 'h' && !p.modifiers[1])
		i = (unsigned short int) i;
	else if (!p.modifiers[0])
		i = (unsigned int) i;
	else if (p.modifiers[0] == 'l' && !p.modifiers[1])
		i = (unsigned long) i;
	return (ft_utoa_base(f, i, "0123456789", 10));
}
