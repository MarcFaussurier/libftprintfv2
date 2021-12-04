#include "ft_printf.h"


int	ft_printf(const char *format, ...)
{
	int 	i;
	va_list	ap;

	va_start(ap, format);
	i = ft_vprintf(format, ap);
	va_end(ap);
	return (i);
}

int	ft_vdprintf(int fd, const char *format, ...)
{
	int 	i;
	va_list	ap;

	va_start(ap, format);
	i = ft_vdprintf(format, ap);
	va_end(ap);
	return (i);
}

int	ft_vsprintf(char *str, const char *format, ...)
{
	int 	i;
	va_list	ap;

	va_start(ap, format);
	i = ft_vdprintf(format, ap);
	va_end(ap);
	return (i);
}


int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	int 	i;
	va_list	ap;

	va_start(ap, format);
	i = ft_vdprintf(format, ap);
	va_end(ap);
	return (i);
}



int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int 	i;
	va_list	ap;

	va_start(ap, format);
	i = ft_vdprintf(format, ap);
	va_end(ap);
	return (i);
}


/*
	parse_flags(&ctx, format);
	ctx.width = parse_int(&ctx, format);
	if (**format == '.')
		ctx.precision = parse_int(&ctx, ++format);
	c1 = *(*format++);
	c2 = *(*format++);
uyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyh	c3 = *(*format++);
	
	ft_printf_route(&ctx)(ap);

	while (**format)
	{
		if (**format == '-')
			ctx.minux = 1;
		else if (**format == '0')
			ctx.zero = 1;
		else if (**format == '+')
			ctx.plus = 1;
		else if (**format == ' ')
			ctx.space = 1;
		else if (**format == '#')
			ctx.sharp = 1;
		else
			break ;
		*format += 1;
	}
	if (**format >= '0' && format <= '9')
*/


