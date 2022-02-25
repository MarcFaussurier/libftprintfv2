/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:27:46 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/25 18:25:44 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_u(t_lambda f, t_fmt_params p, va_list ap)
{
	char		b[64];
	t_pstr		num;
	t_ull		i;

	i = va_arg64(ft_modifiers_to_type(p.modifiers), ap);
	num = (t_pstr){.l = 0, .s = &b[0]};
	ft_cutoa_base((t_lambda){&pstr_write, &num}, i,
		(t_pcstr){10, "0123456789"});
	return (pad_num(f, p, (t_num_pad)
			{
				.num = (t_pstr){.l = num.l, .s = num.s},
			.prefix = (t_pcstr){.l = 0, .s = 0},
		.sign = 0,
	}));
}
