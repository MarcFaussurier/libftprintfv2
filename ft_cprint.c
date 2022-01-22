#include "ftprint.h"

int	ft_cprintstr(t_printchar print, const char *str)
{
	int		r;

	r = 0;
	while (*str)
		r += print(*str++);
	return (r);
}

int	ft_cprintullong_base(t_printchar print, const char *b, int l, unsigned long long n)
{
	int 		r;
	int 		k;
	char		a[65];

	k = 65;
	while (1)
	{
		k -= 1;
		a[k] = b[n % l];
		n = n / l;
		if (!n)
			break ;
	}
	r = 0;
	while (k < 65)
		r += print(a[k++]);
	return (r);
}

int ft_cprintllong_base(t_printchar print, const char *b, int l, long long n)
{
	int 				r;
	int					i;

	r = 0;
	if (n < 0)
		r += print('-');
	if (n == LLONG_MIN)
	{
		i = 0;
		while (LLONG_MIN_A[i])
			r += print(LLONG_MIN_A[i++]);
		return (r);
	}
	else if (n < 0)
		n = -n;
	return (ft_cprintullong_base(print, b, l, n));
}

int ft_cprintldbl(t_printchar print, const char *b, int l, long double f)
{
	return (ft_cprintullong_base(print, b, l, l));
}
