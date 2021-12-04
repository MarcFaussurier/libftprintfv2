#include <stdio.h>
#include <limits.h>
#include <float.h>

#include "libftprintf.h"

int main()
{

	printf("%w %Wadwa% %n\n\n%LG\n", ULLONG_MAX, CHAR_MAX);
	printf("%zG\n\n%LG\n", (float) LDBL_MAX, LDBL_MAX);
	printf("%i", snprintf(0, 0, "%s", "hello"));
}
