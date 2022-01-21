#include "print.h"

int	ft_cprintf(t_printchar printchar, const char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = ft_vcprintf(printchar, format, ap);
	va_end(ap);
	return (i);
}

int	ft_vcprintf(t_printchar print, const char *format, va_list ap)
{
	t_printf_ctx	ctx;
	int				i;

	i = 0;
	while (*format)
		if (*format == '%')
	i += 0;
	else
		i += p(*format++);
	p(0);
	return (i);
}

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

t_printf_hashmap	g_printf_functions = {
[100] = {{"str", _},
	^ int (t_printf_ctx ctx, t_printchar printchar, int i, va_list ap)
{
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ap;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ap;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ap;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ap;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ap;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ap;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ap;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ap;
	return (0);
}},
[0] = {{"a", "g", _},
	^ int (t_printf_ctx ctx, t_printchar printchar, int i, va_list ap)
{
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ctx;
	(void) printchar;
	(void) i;
	(void) ctx;
	(void) printchar;
	(void) i;
	return (0);
}}
};

short int	ft_printf_hash(char *str)
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
