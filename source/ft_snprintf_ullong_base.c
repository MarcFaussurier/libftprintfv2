#include "../libftprintf.h"

int 					ft_snprintf_ullong_base(t_printf_ctx *ctx, char **str, size_t *size, unsigned long long n, const char *b, int bl)
{
	int 				r;
	int 				k;
	int					m;
	char				c;
	char				buffer[65];

	r = 0;
	k = 65;

	while (1)
	{
		k -= 1;
		buffer[k] = b[n % bl];
		n = n / bl;
		if (!n)
			break ;
	}
	if (ctx->sharp && bl == 8 && ctx->precision)
		ctx->precision -= 1;
	if (ctx->sharp)
	{
		if (bl == 8)
		{
			ft_nstr_append(&r, str, size, '0');
		}
		else if (bl == 16 || bl == 8)
		{
			ft_nstr_append(&r, str, size, '0');
			ft_nstr_append(&r, str, size, b[16]);
		}
	}
	while (k < 65)
	{
		ft_nstr_append(&r, str, size, buffer[k]);
		k += 1;
	}
	return (r);
}
