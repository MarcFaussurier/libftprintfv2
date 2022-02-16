/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:53:15 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 15:54:25 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_p(t_lambda f, t_fmt_params p, va_list ap)
{
	unsigned long long	i;
	char		*s;

	i = va_arg(ap, unsigned long long);
	return (
(((t_putchar)f.ptr)('0', f.data)) + 
(((t_putchar)f.ptr)('x', f.data)) + 
			ft_itoa_base(f, i, "0123456789", 16));
}
