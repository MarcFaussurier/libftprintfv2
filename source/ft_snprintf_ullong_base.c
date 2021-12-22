#include "../libftprintf.h"

int 					ft_snprintf_ullong_base(t_printf_ctx *ctx, char **str, size_t *size, unsigned long long n, const char *b)
{
	int 				r;
	int 				y;
	int 				k;
	int 				rrev;

	r = 0;
	k = 0;
	rrev = *size;
	while (1)
	{
		rrev = ft_nstr_append(&r, str, size, (n % 10) + '0') && rrev;
		k += 1;
		n = n / 10;
		if (!n)
			break ;
	}
	y = 0;
	// TODO:: Deal with end of size while itoa was in progress
	// compare with vsnpf behaviour
	if (rrev)
	while (k > y * 2)
	{

		char c;
		c = *(*str - y - 1);
		*(*str - y - 1) = *(*str - k + y);
		*(*str - k + y) = c;
		y += 1;
	}
	return (r);
}
