#include <stdio.h>
#include <limits.h>
#include <float.h>

#include "libftprintf.h"

int main()
{
	ft_printf("42\n");

	printf("%w%hhX Wadwa", ULLONG_MAX, CHAR_MAX);
	printf("%G\n\n%LG\n", (float) LDBL_MAX, LDBL_MAX);
	printf("%i", snprintf(0, 0, "%s", "hello"));
}
