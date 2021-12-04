#include "ft_printf.h"


int	ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	char 	buffer[PRINTF_BUFFER_SIZE + 1];
	int 	i;

	if (!ft_printf_ids[0])
		ft_printf_ids_defaults();
	// todo:: handle overflow
	i = ft_vsnprintf(buffer, format, ap);
	write(fd, buffer, i);
	return (i);
}

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	return (ft_vsnprintf(str, INT_MAX + 1, format, ap));
}


int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	va_list		ap;
	t_printf_ctx 	ctx;

	ctx.i = 0;
	while (*format)
		ctx.i += ft_printf_arg(&ctx, &format, ap)(&ctx, str + ctx.i, size - i, ap);
	return (i);
}



int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int 	i;

	i = ft_vsnprintf(0, 0, format, ap) + 1;
	*ret = malloc(i * sizeof(char));
	if (!*ret)
		return (-1);
	return (ft_vsnprintf(*ret, i, format, ap))
}



