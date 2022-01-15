#include "../libftprintf.h"

int 			ft_vsnprintf_ptr(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	void		*arg;
	int			r;

	r = 0;
	arg = va_arg(ap, void*);
	ctx->sharp = 1;
	r += ft_snprintf_ullong_base(ctx, str, size, (unsigned long long) arg, b16, 16);
	return (r);
}
