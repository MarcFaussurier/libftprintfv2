/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:52:34 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 13:43:24 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	r;

	r = 0;
	while (*s++)
		r += 1;
	return (r);
}

int ft_countc(char c, void *data)
{
	(void) c;
	(void) data;
	return (1);
}

static int	put(char c, void *data)
{
	(void) data;
	write(1, &c, 1);
	return (1);
}

int	ft_vprintf(const char *fmt, va_list ap)
{
	return (ft_vcprintf((t_lambda){&put, 0}, fmt, ap));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		r;

	va_start(ap, fmt);
	r = ft_vprintf(fmt, ap);
	va_end(ap);
	return (r);
}
