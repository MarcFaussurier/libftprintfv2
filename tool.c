#include "./stdio.h"
#include <unistd.h>
#include "./stdio.h"

static int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int main(int ac, char **av)
{
	if (ac <= 1)
	{
		ft_putstr(ft_putchar, "Usage: ");
		ft_putstr(ft_putchar, av[0]);
		ft_putstr(ft_putchar, " string1 string2..\n");
		return (1);
	}
	while (ac > 1)
	{
		ft_putstr(av[--ac]);
		ft_putstr(": ");
		ft_putullong_base(ft_putchar, b10, 10, ft_printf_hash(av[ac]));
		ft_putstr("\n");
	}
	return (0);
}
