#include "../libftprintf.h"
#include "stdio.h"
#include "string.h"

__auto_type g_printf_functions[FT_PRINTF_HASHMAP_SIZE] = {
	[100] = {"str", ^void(){}},
}

int 			g_printf_collisions = 0;

short int 		ft_printf_hash (char *str)
{
    unsigned 	hash;
    unsigned 	i;

    hash = 0;
    i = 0;
    if (str[0] == 'l' && str[1] == 'g')
        return (FT_PRINTF_HASHMAP_SIZE - 42);
    while (str[i])
        hash = 31 * hash + str[i++];
    i = (hash % (FT_PRINTF_HASHMAP_SIZE));
	return (i);
}

void			ft_printf_id_add (t_printf_fn callable, ...)
{
	va_list		ap;
	char		*id;
	int	 	h;

	va_start (ap, callable);
	while (1)
	{
		id = va_arg (ap, char *);
		if (!id[0])
			break ;
		h = ft_printf_hash (id);
		if (g_printf_ids[h])
		{
			printf("error: printf identifier [id=%s, h=%i]", id, h);
			printf(" already exists as %s, use a different label!\n", g_printf_labels[h]);
			g_i += 1;
		}
		else
		{
			g_printf_ids[ft_printf_hash(id)] = callable;
			g_printf_labels[ft_printf_hash(id)] = id;
		}
	}
	va_end(ap);
}

static int		ft_read_num(char const **fmt, va_list ap)
{
	int			o;

	o = 0;
	if (**fmt == '*')
	{
		(*fmt) += 1;
		return (va_arg(ap, int));
	}
	while ((((**fmt) >= '0') && (**fmt <= '9')))
	{
		o *= 10;
		o += **fmt - '0';
		*fmt += 1;
	}
	return (o);
}

t_printf_fn		ft_printf_arg (t_printf_ctx *ctx, const char **format, va_list ap)
{
	char		label[11];
	short int 	hash;
	char		c;

	*ctx = (t_printf_ctx)
	{
		.falgs = 0,
		.width = 0, // init with a negative value ?
		.precision = 0,
	};
	while (1)
	{

		c = **format;
		if (c == '-')
			ctx->minus = 1;
		else if (c == '0')
			ctx->zero = 1;
		else if (c == '.')
		{
			ctx->dot = 1;
			*format += 1;
			if (**format >= '0' && **format <= '9')
			{
				ctx->precision = ft_read_num(format, ap);
				continue ;
			}
		}
		else if (c == '#')
			ctx->sharp = 1;
		else if (c == ' ')
			ctx->space = 1;
		else if (c == '+')
			ctx->plus = 1;
		else if (c < '0' || c > '9')
			break ;
		if (c >= '0' && c <= '9')
			ctx->width = ft_read_num(format, ap);
		else
			*format += 1;
	}
	i = 0;
	while (**format)
	{
		label[i] = *format[i];
		if (!**format)
			break ;
		*format += 1;
		label[i] = 0;
		hash = ft_printf_hash(label);
		if (!g_printf_ids[hash])
			continue ;
		if (strcmp (label, g_printf_labels[hash]))
			continue ;
		return (g_printf_ids[hash]);
	}
	i = 0;
	while (label[i])
		i += putchar(i, label[i]);
	return (i);
}
