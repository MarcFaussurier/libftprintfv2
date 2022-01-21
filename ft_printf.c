#include "./stdio.h"

int	ft_printf(const char *format, ...)
{
	int 	i;
	va_list	ap;

	va_start(ap, format);
	i = ft_vprintf(format, ap);
	va_end(ap);
	return (i);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int 	i;
	va_list	ap;

	va_start(ap, format);
	i = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (i);
}

int	ft_sprintf(char *str, const char *format, ...)
{
	int 	i;
	va_list	ap;

	va_start(ap, format);
	i = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (i);
}


int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	int 	i;
	va_list	ap;

	va_start(ap, format);
	i = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (i);
}

int	ft_asprintf(char **ret, const char *format, ...)
{
	int 	i;
	va_list	ap;

	va_start(ap, format);
	i = ft_asprintf(ret, format, ap);
	va_end(ap);
	return (i);
}v
