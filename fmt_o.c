/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:42:54 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/25 15:14:29 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_o(t_lambda f, t_fmt_params p, va_list ap)
{
	char		sign;
	char		b[64];
	t_pstr		num;
	t_ull		i;
	t_pcstr		prefix;

	i = va_arg64(ft_modifiers_to_type(p.modifiers), ap);
	num = (t_pstr){.l = 0, .s = &b[0]};
	ft_cutoa_base((t_lambda){&pstr_write, &num}, i, (t_pcstr){8, "01234567"});
	prefix = (t_pcstr){.l = 1, .s = "0"};
	sign = 0;
	return (pad_num(f, p, (t_num_pad)
			{
				.num = (t_pstr){.l = num.l, .s = num.s},
			.prefix = prefix,
			.sign = 0
		}));
}
