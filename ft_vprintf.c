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

	ctx.format = &format;
	if (!g_printf_ids[0])
	{
		ft_printf_default();
		printf("--------------------\n");
		printf(" - %i ft_printf hashmap collisions.\n", g_i);
		printf("--------------------\n");
		if (!g_printf_ids[0])
			g_printf_ids[0] = 1;
	}
	i = 0;
	while (*format)
		if (*format == '%')
			i += ft_printf_arg(&ctx, ap)(&ctx, &str, &size, ap);
		else
			i += ft_vsnprintf_fmt(&ctx, &str, &size, ap);
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
	i = ft_vsnprintf(0, 0, format, apc) + 1;
	va_end(apc);
	*ret = malloc(i * sizeof(char));
	if (!*ret)
		return (-1);
	return (ft_vsnprintf(*ret, i, format, ap));
}
