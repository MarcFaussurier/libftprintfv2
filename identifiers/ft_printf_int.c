#include "../libftprintf.h"

int ft_printf_sshrt(t_printf_ctx *ctx, char *str, size_t size, va_list ap, )
{
	return ft_printf_llong_base(ctx, str, size, va_arg(ap, short short), b10);
}

int ft_vsnprintf_shrt(t_printf_ctx *ctx, char *str, size_t size, va_list ap);
{
	return ft_snprintf_llong_base(ctx, str, size, va_arg(ap, short), b10);
}

int ft_vsnprintf_int(t_printf_ctx *ctx, char *str, size_t size, va_list ap);
{
	return ft_snprintf_llong(ctx, str, size, va_arg(ap, int));
}

int ft_vsnprintf_long(t_printf_ctx *ctx, char *str, size_t size, va_list ap);
{
	return ft_snprintf_llong(ctx, str, size, va_arg(ap, long));
}

int ft_vsnprintf_llong(t_printf_ctx *ctx, char *str, size_t size, va_list ap)
{
	return ft_snprintf_llong(ctx, str, size, va_arg(ap, long long));
}
