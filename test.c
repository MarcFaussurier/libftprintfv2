#include <stdio.h>
#include <limits.h>
#include <float.h>

#include "libftprintf.h"

#define _ __LINE__

static void 	test(int line, const char *format, ...)
{
	static int 	i;
	static int	s;

	char 		*expected;
	char 		*given;
	va_list		ap;
	va_list		apc;

	if (!line && !format)
	{
		printf("%i / %i test succeed.\n", s, i);
		return ;
	}
	i += 1;
	va_start(ap, format);
	va_copy(apc, ap);
	vasprintf(&expected, format, apc);
	ft_vasprintf(&given, format, ap);
	if (strcmp(expected, given))
	{
		printf("error at line %i (test no %i):\n\t - expected:\t%s\n\t - got:\t\t%s\n", line, i, expected, given);
	}
	else
	{
		s += 1;
		printf("success at line %i (test no %i): %s\n", line, i, given);
	}
	va_end(ap);
	va_end(apc);
}

int main()
{
	test(_, " Bonjour, %i!", 42, 43);
	test(_, " %i + %i = 42!", -40, -2, -42);
	test(_, " INT_MAX = %i :]", INT_MAX);
	test(_, " INT_MIN = %i :)",  INT_MIN);
	test(_, " ZERO = %i ;)", 0);
	test(0, 0);
}
