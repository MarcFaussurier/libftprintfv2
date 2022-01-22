#include <stdlib.h>
#include "libftprintf.h"

int	ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	__block int _fd;	

	_fd = fd;
	return (ft_vcprintf((void*) ^ int (char c){
		write(_fd, &c, 1);
		return (1);
	}, format, ap));
}

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	return (ft_vsnprintf(str, INT_MAX, format, ap));
}

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	__block int _size;
	__block int _y;

	_size = size - 1;
	_y = 0;
	return (ft_vcprintf((void*)^ int (char c){
		if (_y < _size || (_y == _size && !c))
		{
			if (str)
			{
				str[_y] = c;
				_y += 1;
			}
		}
		return (1);
	}, format, ap));
}


int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int 	i;
	va_list	apc;

	
	*ret = malloc(FT_ASPRINTF_BUFFER_MIN * sizeof(char));
	if (!*ret)
		return (-1);
	va_copy(apc, ap);
	i = ft_vsnprintf(*ret, FT_ASPRINTF_BUFFER_MIN, format, apc);
	va_end(apc);
	if (i > FT_ASPRINTF_BUFFER_MIN)
		return (ft_vsnprintf(*ret, i + 1, format, apc));
	return (i);
}
