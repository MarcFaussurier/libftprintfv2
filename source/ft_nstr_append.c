#include "../libftprintf.h"

int		ft_nstr_append(int *i, char **str, size_t *size, char c)
{
	*i += 1;
	if (*size > 1)
	{
		*size -= 1;
		**str = c;
		*str += 1;
		return (1);
	}
	return (0);
}

int 		ft_vsnprintf_fmt(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	int 		r;

	(void) ap;
	r = 0;
	ft_nstr_append(&r, str, size, **(ctx->format));
	*(ctx->format) += 1;
	return (1);
}
