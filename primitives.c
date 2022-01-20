#include "./stdio.h"

int	ft_putstr(t_putchar put, char *str)
{
	int		r;

	r = 0;
	while (*str)
		r += put(*str++);
	return (r);
}

int	ft_putullong_base(t_putchar put, const char *b, int l, unsigned long long n)
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
		r += put(a[k++]);
	return (r);
}

int ft_putllong_base(t_putchar put, const char *b, int l, long long n)
{
	int 				r;
	int					i;

	r = 0;
	if (n < 0)
		r += put('-');
	if (n == LLONG_MIN)
	{
		i = 0;
		while (LLONG_MIN_A[i])
			r += put(LLONG_MIN_A[i++]);
		return (r);
	}
	else if (n < 0)
		n = -n;
	return (ft_putullong(put, b, l, n));
}

int ft_putldbl(t_putchar put, const char *b, int l, long double f)
{
	int 				r;
	int					i;

	r = 0;
	if (n < 0)
		r += put('-');
	if (n == LLONG_MIN)
	{
		i = 0;
		while (LLONG_MIN_A[i])
			r += put(LLONG_MIN_A[i++]);
		return (r);
	}
	else if (n < 0)
		n = -n;
	return (ft_putullong(put, n, b, l));
}
