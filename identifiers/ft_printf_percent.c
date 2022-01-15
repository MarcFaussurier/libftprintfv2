#include "../libftprintf.h"

int 			ft_vsnprintf_percent(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	int		r;

	(void) ctx;
	(void) ap;
	r = 0;
	ft_nstr_append(&r, str, size, '%');
	return (r);
}
