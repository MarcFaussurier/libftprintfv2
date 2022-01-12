#include "../libftprintf.h"

int 					ft_snprintf_ullong_base(t_printf_ctx *ctx, char **str, size_t *size, unsigned long long n, const char *b)
{
	int 				r;
	int 				y;
	int 				k;
	char				c;
	char				buffer[65];

	r = 0;
	k = 65;
	while (1)
	{
		k -= 1;
		buffer[k] = n % 10 + '0';
		n = n / 10;
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
