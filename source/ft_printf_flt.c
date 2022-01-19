#include <stdio.h>

void	ft_printf_ldbl(long double f)
{
	char		buffer[255];
	int			i;
	long long	x;
	long long	y;
	long double	g;

	i = 1;
	g = f;
	while (g > (long double)0)
	{
		g = g / 10;
		i = i + 1;
	}
	printf("i: %i\n", i);

}

int main()
{
	ft_printf_ldbl(0);
	ft_printf_ldbl(1);
	ft_printf_ldbl(101);
	ft_printf_ldbl(42);
}
