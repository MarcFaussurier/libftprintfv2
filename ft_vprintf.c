#include "libftprintf.h"


int	ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	char 	buffer[PRINTF_BUFFER_SIZE + 1];
	int 	i;

	buffer[0] = 0;
	i = ft_vsnprintf(buffer, PRINTF_BUFFER_SIZE, format, ap);
	write(fd, buffer, i);
	return (i);
}

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	return (ft_vsnprintf(str, (size_t)INT_MAX, format, ap));
}

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	t_printf_ctx 	ctx;
	int				i;
	size_t			y;
	va_list			apc;
	char			*str2;
	const char		*fmt2;

	ctx.format = &format;
	// TODO : replace default init by global arrays 
	ft_printf_default();
	i = 0;
	while (*format)
		if (*format == '%')
		{
			if (ctx.width)
			{
				// TODO: more clear 
				// TODO: arg width 
				// TODO: better prototypes
				y = 0;
				va_copy (apc, ap);
				str2 = str;
				fmt2 = format;
				y= ft_printf_arg(&ctx, ap)(&ctx, &str2, &y, apc);
				format = fmt2;
				while (ctx.width > y)
				{
					ft_nstr_append(&i, &str, &size, ' ');
					ctx.width -= 1;
				}
				va_end(apc);
			}
			i += ft_printf_arg(&ctx, ap)(&ctx, &str, &size, ap);
		}
		else
			i += ft_vsnprintf_fmt(&ctx, &str, &size, ap);
	// TODO : check bellow
	if (i < size) 
		str[i] = 0;
	if (size)
		str[size - 1] = 0;
	return (i);
}


int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int 	i;
	va_list	apc;

	va_copy(apc, ap);
	i = 42;//ft_vsnprintf(0, 0, format, apc) + 1;
	va_end(apc);
	*ret = malloc(i * sizeof(char));
	if (!*ret)
		return (-1);
	return (ft_vsnprintf(*ret, i, format, ap));
}
