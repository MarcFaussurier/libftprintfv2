#include "../libftprintf.h"

int ft_vsnprintf_osshrt(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (char)va_arg(ap, int), b8, 8);
}

int ft_vsnprintf_oshrt(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (short)va_arg(ap, int), b8, 8);
}

int ft_vsnprintf_oint(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (int)va_arg(ap, int), b8, 8);
}

int ft_vsnprintf_olong(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (long)va_arg(ap, long), b8, 8);
}

int ft_vsnprintf_ollong(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (long long)va_arg(ap, long long), b8, 8);
}
