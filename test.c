#include <stdio.h>
#include <limits.h>
#include <float.h>

#include "libftprintf.h"

int main()
{
	ft_printf("TEST\t1\t: %i\n", -4201);
	ft_printf("TEST\t2\t: %i\n", LLONG_MAX);
	ft_printf("TEST\t3\t: %i\n", 4201);
	ft_printf("TEST\t4\t: %i\n", 0);
	ft_printf("TEST\t5\t: %i\n", 4);
}
