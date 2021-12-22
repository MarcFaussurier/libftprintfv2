#include "../libftprintf.h"

int 					ft_snprintf_ullong_base(t_printf_ctx *ctx, char **str, size_t size, unsigned long long n, const char *b)
{
	int 				r;
	int 				y;
	int 				k;

	r = 0;
	k = 0;

	while (1)
	{
		ft_nstr_append(&r, str, &size, (n % 10) + '0');
		k += 1;
		n = n / 10;
		if (!n)
			break ;
	}
	**str = 0;	
	y = 0;
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
