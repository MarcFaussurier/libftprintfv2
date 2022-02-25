/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:38:42 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/25 13:25:31 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdlib.h"

typedef struct s_p2str
{
	int		l;
	int		i;
	char	*s;
}	t_p2str;

static int	f(char c, t_p2str *data)
{
	if (data->i < data->l)
	{
		data->s[data->i] = c;
		data->i += 1;
	}
	return (1);
}

int	ft_vasprintf(char **s, const char *fmt, va_list ap)
{
	va_list	lap;
	t_p2str	str;

	str.s = malloc(4096 + 1);
	str.l = 4096;
	str.i = 0;
	va_copy(lap, ap);
	str.l = (ft_vcprintf((t_lambda){.ptr = &f, .data = &str}, fmt, ap));
	if (str.l > 4096)
	{
		free(str.s);
		str.i = 0;
		str.s = malloc(str.l + 1);
		str.l = (ft_vcprintf((t_lambda){.ptr = &f, .data = &str}, fmt, lap));
	}
	va_end(lap);
	if (str.l >= 0)
	{
		str.s[str.l] = 0;
		*s = str.s;
	}
	else
		*s = 0;
	return (str.l);
}

int	ft_asprintf(char **s, const char *fmt, ...)
{
	va_list	ap;
	int		r;

	va_start(ap, fmt);
	r = ft_vasprintf(s, fmt, ap);
	va_end(ap);
	return (r);
}
