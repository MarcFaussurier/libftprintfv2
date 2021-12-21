#include "libftprintf.h"


int	ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	char 	buffer[PRINTF_BUFFER_SIZE + 1];
	int 	i;

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

	if (!g_printf_ids[0])
		ft_printf_default();
	printf("--------------------\n");
	printf("%i ft_printf hashmap collisions.\n", g_i);
	printf("--------------------\n");
	i = 0;
	while (*format)
		if (*format == '%' && ++format)
			i += ft_printf_arg(&ctx, &format, ap)(&ctx, str + i, size - i, ap);
		else 
		{
			if (size--)
				str[i] =  *format;
			i += 1;
			format += 1;
		}	
	if (i < size) 
		str[i] = 0;
	if (size)
		str[size] = 0;
	return (i);
}

int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int 	i;

	i = ft_vsnprintf(0, 0, format, ap) + 1;
	*ret = malloc(i * sizeof(char));
	if (!*ret)
		return (-1);
	return (ft_vsnprintf(*ret, i, format, ap));
}
