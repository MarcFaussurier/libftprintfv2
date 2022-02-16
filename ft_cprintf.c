/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:43:22 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 11:56:32 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

const int fmt_i(void(*c)(char, void*), void *data, const char modifiers[3], va_list ap)
{
	long long	i;
	char 		*s;

	i = va_arg(ap, long long);
	asprintf(&s, "%i", i);
	while (*s)
	{
		c(*s, data);
		s += 1;
	}
	return (0);
}


static const 
int (*g_specifiers[255])(
		void(*c)(char, void*), void * data, const char modifiers[3], va_list ap) = {
	['i'] = fmt_i
};

int	ft_vcprintf(void(*c)(char c, void *data), void *data,
		const char *fmt, va_list ap)
{
	char	modifiers[3];
	int		i;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt += 1;
			i = 0;
			while ((*fmt == 'h' || *fmt == 'l' || *fmt == 'L' || *fmt == 'z')
					&& i < 2)
				modifiers[i++] = *fmt++;
			modifiers[i] = 0;
			if (g_specifiers[*fmt])
				g_specifiers[*fmt](c, data, modifiers, ap);
			else
				ft_vcprintf(c, data, modifiers, ap);
		}
		else
			c(*fmt, data);
		fmt += 1;
	}
	return (0);
}

int	ft_cprintf(void(*c)(char c, void *data), void *data, const char *fmt, ...)
{
	va_list	ap;
	int		r;

	va_start(ap, fmt);
	r = ft_vcprintf(c, data, fmt, ap);
	va_end(ap);
	return (0);
}

int	main(int ac, char **av)
{
	ft_printf("args:\n");
	ft_printf("%hhi %p\n", 42);
	while (ac)
	{
		ft_printf(av[--ac]);
		ft_printf("\n");
	}
	return (0);
}
