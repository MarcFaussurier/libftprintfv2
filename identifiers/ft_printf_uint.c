#include "../libftprintf.h"

int ft_vsnprintf_usshrt(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (char)va_arg(ap, int), b10);
}

int ft_vsnprintf_ushrt(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (short)va_arg(ap, int), b10);
}

int ft_vsnprintf_uint(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (int)va_arg(ap, int), b10);
}

int ft_vsnprintf_ulong(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (long)va_arg(ap, long), b10);
}

int ft_vsnprintf_ullong(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (long long)va_arg(ap, long long), b10);
}
