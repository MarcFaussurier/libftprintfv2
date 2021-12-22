#include "../libftprintf.h"

int ft_vsnprintf_sshrt(t_printf_ctx *ctx, char **str, size_t size, va_list ap)
{
	return ft_snprintf_llong_base(ctx, str, size, (char)va_arg(ap, int), b10);
}

int ft_vsnprintf_shrt(t_printf_ctx *ctx, char **str, size_t size, va_list ap)
{
	return ft_snprintf_llong_base(ctx, str, size, (short)va_arg(ap, int), b10);
}

int ft_vsnprintf_int(t_printf_ctx *ctx, char **str, size_t size, va_list ap)
{
	return ft_snprintf_llong_base(ctx, str, size, (int)va_arg(ap, int), b10);
}

int ft_vsnprintf_long(t_printf_ctx *ctx, char **str, size_t size, va_list ap)
{
	return ft_snprintf_llong_base(ctx, str, size, (long)va_arg(ap, long), b10);
}

int ft_vsnprintf_llong(t_printf_ctx *ctx, char **str, size_t size, va_list ap)
{
	return ft_snprintf_llong_base(ctx, str, size, (long long)va_arg(ap, long long), b10);
}
