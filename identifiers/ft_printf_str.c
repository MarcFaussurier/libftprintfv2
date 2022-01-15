#include "../libftprintf.h"

int 			ft_vsnprintf_str(t_printf_ctx *ctx, char **str, size_t *size, va_list ap)
{
	char		*arg;
	int			r;

	(void) ctx;
	r = 0;
	arg = va_arg(ap, char *);
	if (!arg)
		arg = "(null)";
	while (*arg)
		ft_nstr_append(&r, str, size, *arg++);
	return (r);
}
