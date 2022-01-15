#include "../libftprintf.h"

int 			ft_vsnprintf_char(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	char		c;
	int			r;

	(void) ctx;
	r = 0;
	c = va_arg(ap, int);
	ft_nstr_append(&r, str, size, c);
	return (r);
}
