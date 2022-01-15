#include "../libftprintf.h"

int ft_vsnprintf_xsshrt_up(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (char)va_arg(ap, int), B16, 16);
};

int ft_vsnprintf_xshrt_up(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (short)va_arg(ap, int), B16, 16);
}

int ft_vsnprintf_xint_up(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (int)va_arg(ap, int), B16, 16);
}

int ft_vsnprintf_xlong_up(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (long)va_arg(ap, long), B16, 16);
}

int ft_vsnprintf_xllong_up(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	return ft_snprintf_ullong_base(ctx, str, size, (long long)va_arg(ap, long long), B16, 16);
}
