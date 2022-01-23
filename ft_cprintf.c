#include "libftprintf.h"

#include "stdio.h"

#if DYNAMIC_PRINTF == 0

static const
#endif
t_printf_hashmap g_printf_hashmap = {
[120] = {{"x", 0},
	^ int (t_printf_context ctx, t_printchar print, int i, va_list ap)
{
	return (ft_cprintullong_base(print, B16, 16, va_arg(ap, int)));
}
}
,
[105] = {{"i", "d", 0},
	^ int (t_printf_context ctx, t_printchar print, int i, va_list ap)
{
	return (ft_cprintllong_base(print, B10, 10, va_arg(ap, int)));
}
}
,
[115] = {{"s", 0},
	^ int (t_printf_context ctx, t_printchar print, int i, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	return (ft_cprintstr(print, str));
}
}
}
;
//

static int	ft_read_num(char const **fmt, va_list ap)
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

int	ft_cprintf(t_printchar print, const char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = ft_vcprintf(print, format, ap);
	va_end(ap);
	return (i);
}

int	ft_vcprintf(t_printchar print, const char *format, va_list ap)
{
	t_printf_context	ctx;
	int					i;
	int					y;
	int					z;
	int					n;
	int					hash;
	char                label[FT_PRINTF_LABEL_SIZE + 1];

	i = 0;
	while (*format)
		if (*format == '%')
		{
			format += 1;
			printf("-format:%s\n", format);
			y = 0;
			z = 0;
			while (format[y] && y < FT_PRINTF_LABEL_SIZE)
			{
				label[y] = format[y];
				label[y + 1] = 0;
				hash = ft_printf_hash(label);
			z = 0;
				while (g_printf_hashmap[hash].s[z])
				{
					if (!ft_strcmp(label, g_printf_hashmap[hash].s[z]))
					{
						i += g_printf_hashmap[hash].f(ctx, print, i, ap);
						z = -1;
						format += y + 1;
						break ;
					}
					z += 1;
				}
				if (z == -1)
					break;
				y += 1;
			}
			if (z != -1)
			{
				i += print(*format++);
			}
		}
	T T else
		T T i += print(*format++);
	print(0);
	return (i);
}

short int	ft_printf_hash(const char *str)
{
	unsigned int	hash;
	unsigned int	i;

	hash = 0;
	i = 0;
	if (str[0] == 'l' && str[1] == 'g')
		return (FT_PRINTF_HASHMAP_SIZE - 42);
	while (str[i])
		hash = 31 * hash + str[i++];
	i = (hash % (FT_PRINTF_HASHMAP_SIZE));
	return (i);
}


