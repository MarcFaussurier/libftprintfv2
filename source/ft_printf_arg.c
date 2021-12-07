#include "../libftprintf.h"
#include "stdio.h"

t_printf_fn		g_printf_ids[127 * 3];

short int		ft_printf_hash(char *str)
{
	int			i;

	i = 0;
	while (*str)
	{
		i += *str;
		str += 1;
	}
	return (i);
}

void		ft_printf_id_add(t_printf_fn callable, ...)
{
	va_list		ap;
	char		*id;
	int	 	h;

	va_start(ap, callable);
	while (1)
	{
		id = va_arg(ap, char *);
		if (!id)
			break;
		h = ft_printf_hash(id);
		if (g_printf_ids[h])
		{
			printf("ft_printf: warning identifier \
					[id=%s, h=%i] already exists!\n",
					id, h);
		}
		g_printf_ids[ft_printf_hash(id)] = callable;
	}
	va_end(ap);
}

t_printf_fn		ft_printf_arg(t_printf_ctx *ctx, const char **format, va_list ap)
{
	return (0);
}
