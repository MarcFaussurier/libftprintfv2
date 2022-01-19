#include "libftprintf.h"

int 			ft_vcprintf(t_putchar putchar, const char *format, va_list ap)
{
	t_printf_ctx 	ctx;
	int				i;

	// TODO: replace by a global array definition
	ft_printf_default();
	i = 0;
	while (*format)
		if (*format == '%')
			i += ft_printf_arg(&ctx, &(++format), i, ap)(ctx, putchar, i, ap);
		else
			i += putchar(i, *format++);
	putchar(i, 0);
	return (i);
}

int 			ft_cprintf(t_putchar putchar, const char *format, ...)
{
	va_list		ap;
	int			i;

	ap = va_arg(ap. format);
	i = ft_vcprintf(putchar, fornmat, ap);
	va_end(ap);
	return (i);
}
