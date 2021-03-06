/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:46:33 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/25 18:53:13 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	generic_fmt_x(t_lambda f, t_fmt_params p,
		va_list ap, int up)
{
	char		b[64];
	t_pstr		num;
	t_ull		i;
	t_pcstr		prefix;

	i = va_arg64(ft_modifiers_to_type(p.modifiers), ap);
	num = (t_pstr){.l = 0, .s = &b[0]};
	if (up)
	{
		ft_cutoa_base((t_lambda){&pstr_write, &num}, i,
			(t_pcstr){16, "0123456789ABCDEF"});
		prefix = (t_pcstr){.l = 2, .s = "0X"};
	}
	else
	{
		ft_cutoa_base((t_lambda){&pstr_write, &num}, i,
			(t_pcstr){16, "0123456789abcdef"});
		prefix = (t_pcstr){.l = 2, .s = "0x"};
	}
	return (pad_num(f, p, (t_num_pad)
			{
				.num = (t_pstr){.l = num.l, .s = num.s},
			.prefix = prefix,
			.sign = 0, .force_prefix = 0
		}));
}

int	fmt_x(t_lambda f, t_fmt_params p, va_list ap)
{
	return (generic_fmt_x(f, p, ap, 0));
}

int	fmt_x_up(t_lambda f, t_fmt_params p, va_list ap)
{
	return (generic_fmt_x(f, p, ap, 1));
}
