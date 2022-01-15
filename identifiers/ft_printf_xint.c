#include "../libftprintf.h"

int ft_vsnprintf_xsshrt(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (char)va_arg(ap, int), b16, 16);
}

int ft_vsnprintf_xshrt(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (short)va_arg(ap, int), b16, 16);
}

int ft_vsnprintf_xint(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (int)va_arg(ap, int), b16, 16);
}

int ft_vsnprintf_xlong(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (long)va_arg(ap, long), b16, 16);
}

int ft_vsnprintf_xllong(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (long long)va_arg(ap, long long), b16, 16);
}
