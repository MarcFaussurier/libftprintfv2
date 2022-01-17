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
	long double elapsed, elapsed2;
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
		printf("[speed: %+Lf%%] success at line %i (test no %i): %s\n", elapsed - elapsed2, line, i, given);
	}
	va_end(ap);
	va_end(apc);
}


int main()
{
	printf("----------------------------------------\n--- boot time\n");
	test(_, "boot time test");
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
	//
 	test(_, "un%#Jnow");
	test(_, " %#i", 42);

	test(_, " %#x", 42);

	test(_, " %#4X", 42);

	test(_, " %#p", 42);

	test(_, " %2.1o", 42);
	/*

	test(_, "%#c is that a L?", 'L');
	test(_, "%#c is that \xff ? ", '\xff');
	test(_, "is '%#s' '(null) ?", 0);
	test(_, "is '%#s' 'le 101' ?", "le 101");
	test(_, "%#p ptr test!", 798797);
	test(_, "%#p ptr test 2!", 0);
	test(_, "%#d", 42);
	test(_, "Bonjour, %#i! %", 42, 43);
	test(_, "%i + %d= %i!", -40, -2, -42);
	test(_, "INT_MAX = %i :]", INT_MAX);
	test(_, " INT_MIN = %i :)",  INT_MIN);
	test(_, " ZERO = %i ;)", 0);
	test(_, "octal %#o! ", 42);
	test(_, "octal %#u! ", 42);
	test(_, "is '%#x' is that'f' ?\n", 15);
	test(_, "is '%#X' is that'f' ?\n", 15);
	test(_, "is '%#%' a percent ?"); */
	//
	test(0, 0);
	printf("----------------------------------------\n--- bonus tests\n");
	printf("----------------------------------------\n--- personal tests\n");
	printf("----------------------------------------\n--- testing if vsnpf trims correctly\n");
	char	buffer[255];
	char	buffer2[255];
	snprintf(buffer, 5, "-%i", 12345);
	printf("GCC: %s\n", buffer);
	ft_snprintf(buffer2, 5, "-%i", 12345);
	printf("YOU: %s\n", buffer2);
	if (!strcmp(buffer, buffer2))
		printf ("OK\n");
	else
		printf ("KO\n");


}
