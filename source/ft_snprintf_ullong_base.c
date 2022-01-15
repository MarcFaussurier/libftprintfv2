#include "../libftprintf.h"

int 					ft_snprintf_ullong_base(t_printf_ctx *ctx, char **str, size_t *size, unsigned long long n, const char *b, int bl)
{
	int 				r;
	int 				y;
	int 				k;
	char				c;
	char				buffer[65];

	r = 0;
	k = 65;
	if (ctx->sharp)
	{
		if (bl == 16 || bl == 8)
			ft_nstr_append(&r, str, size, b[0]);
		if 	(bl == 16)
			ft_nstr_append(&r, str, size, b[16]);
	}
	while (1)
	{
		k -= 1;
		buffer[k] = b[n % bl];
		n = n / bl;
		if (!n)
			break ;
	}
	while (k < 65)
	{
		ft_nstr_append(&r, str, size, buffer[k]);
		k += 1;
	}
	return (r);
}
