#include "printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <float.h>
#include <sys/time.h>
#undef _
#define _ __LINE__

static void 	test(int line, const char *format, ...)
{
	static int 	i;
	static int	s;

	char 		expected[2048];
	char 		given[2048];
	va_list		ap;
	va_list		apc;
	struct timeval begin, end;
	long long ms, ms2;
	if (!line && !format)
	{
		printf("%i / %i test succeed.\n", s, i);
		s = 0;
		i = 0;
		return ;
	}
	i += 1;
	va_start(ap, format);
	va_copy(apc, ap);
    gettimeofday(&begin, 0);
	vsprintf(expected, format, apc);
    gettimeofday(&end, 0);
    ms = end.tv_usec - begin.tv_usec;
	gettimeofday(&begin, 0);
	ft_vsprintf(given, format, ap);
	gettimeofday(&end, 0);
    ms2 = end.tv_usec - begin.tv_usec;
	if (strcmp(expected, given))
	{
		printf("error at line %i (test no %i):\n\t - expected:\t%s\n\t - got:\t\t%s\n", line, i, expected, given);
	}
	else
	{
		s += 1;
		printf("[speed: %+llims] success at line %i (test no %i): %s\n", ms - ms2, line, i, given);
	}
	va_end(ap);
	va_end(apc);
}


int main()
{
	char 	b[10];
	char	buffer[255];
	char	buffer2[255];

	ft_sprintf(b, "Hello!'n");
	printf("----------------------------------------\n--- madatory tests\n");
	test(_, "un%k%Jnow");;
	test(_, "%c is that a L?", 'L');
	test(_, "%c is that \xff ? ", '\xff');
	test(_, "is '%s' '(null) ?", 0);
	test(_, "is '%s' 'le 101' ?", "le 101");
	test(_, "%p ptr test!", 798797);
	test(_, "%p ptr test 2!", 0);
	test(_, "%d", 42);
	test(_, "Bonjour, %i! %", 42, 43);
	test(_, "%i + %d= %i!", -40, -2, -42);
	test(_, "INT_MAX = %i :]", INT_MAX);
	test(_, " INT_MIN = %i :)",  INT_MIN);
	test(_, " ZERO = %i ;)", 0);
	test(_, "octal %o! ", 42);
	test(_, "octal %u! ", 42);
	test(_, "is '%x' is that'f' ?\n", 15);
	test(_, "is '%X' is that'F' ?\n", 15);
	test(_, "is '%%' a percent ?");
 	test(_, "un%#Jnow");
	test(_, " %#i", 42);
	test(_, " %#x", 42);
	test(_, " %#4X", 42);
	test(_, " %#p", 42);
	test(_, "%04s", "d");
	test(_, " %#2.3i", 42);
	test(_, " %#6.3o", 42);
	test(_, " %#2.3x", 42);
	printf("----------------------------------------\n--- bonus tests\n");
	printf("----------------------------------------\n--- personal tests\n");
	test(0, 0);
	printf("----------------------------------------\n--- testing if vsnpf trims correctly\n");
	snprintf(buffer, 5, "-%i", 12345);
	printf("GCC: %s\n", buffer);
	ft_snprintf(buffer2, 5, "-%i", 12345);
	printf("YOU: %s\n", buffer2);
	if (!strcmp(buffer, buffer2))
		printf ("OK\n");
	else
		printf ("KO\n");
}
