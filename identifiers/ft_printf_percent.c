#include "../libftprintf.h"

int 			ft_vsnprintf_percent(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	(void) str;
	(void) ctx;
	(void) size;
	(void) ap;
	int		r;

	ft_nstr_append(&r, str, size, '%');
	return (r);
}
