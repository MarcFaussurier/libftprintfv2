#include "../libftprintf.h"

int 					ft_snprintf_ullong_base(t_printf_ctx *ctx, char *str, size_t size, unsigned long long n, const char *b)
{
	int 				r;
	int 				y;
	int 				k;

	r = 0;
	k = 0;
	y = 0;
	ft_nstr_append(&r, &str, &size, '-');
	while (1)
	{
		ft_nstr_append(&r, &str, &size, n % 10);
		k += 1;
		n /= 10;
		if (!n)
			break ;
	}
	while (k - y >= 0)
	{
		*(str - y) = *(str - k + y);
		y += 1;
	}
	ft_nstr_append(&r, &str, &size, 0);
	return (r);
}
