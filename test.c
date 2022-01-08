#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <float.h>
#include <sys/time.h>

#include "libftprintf.h"

#undef _
#define _ __LINE__

static void 	test(int line, const char *format, ...)
{
	static int 	i;
	static int	s;

	char 		*expected;
	char 		*given;
	va_list		ap;
	va_list		apc;
	struct timeval begin, end;
	long seconds, microseconds;
	double elapsed, elapsed2;
	if (!line && !format)
	{
		printf("%i / %i test succeed.\n", s, i);
		return ;
	}
	i += 1;
	va_start(ap, format);
	va_copy(apc, ap);
    gettimeofday(&begin, 0);
	vasprintf(&expected, format, apc);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;
	gettimeofday(&begin, 0);
	ft_vasprintf(&given, format, ap);
	gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed2 = seconds + microseconds*1e-6;
	if (strcmp(expected, given))
	{
		printf("error at line %i (test no %i):\n\t - expected:\t%s\n\t - got:\t\t%s\n", line, i, expected, given);
	}
	else
	{
		s += 1;
		printf("[speed: +%f%%] success at line %i (test no %i): %s\n", elapsed2 - elapsed, line, i, given);
	}
	va_end(ap);
	va_end(apc);
}

int main()
{
	test(_, " Bonjour, %i!", 42, 43);
	test(_, " %i + %i = %i!", -40, -2, -42);
	test(_, " INT_MAX = %i :]", INT_MAX);
	test(_, " INT_MIN = %i :)",  INT_MIN);
	test(_, " ZERO = %i ;)", 0);
	test(0, 0);
}
