/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:53:15 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/25 18:51:26 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_p(t_lambda f, t_fmt_params p, va_list ap)
{
	char		b[64];
	t_pstr		num;
	t_ull		i;

	i = va_arg64(UL, ap);
	num = (t_pstr){.l = 0, .s = &b[0]};
	ft_cutoa_base((t_lambda){&pstr_write, &num}, i,
		(t_pcstr){16, "0123456789abcdef"});
	p.sharp = 1;
	return (pad_num(f, p, (t_num_pad)
			{
				.num = (t_pstr){.l = num.l, .s = b},
			.prefix = (t_pcstr){.l = 2, .s = "0x"},
		.sign = 0,
		.force_prefix = 1
	}));
}
