#include "libftprintf.h"

int ft_strcmp(char *a, char *b)
{
	while (*a == *b)
	{
	
		if (!*a)
			break ;
		a += 1;
		b += 1;
	}
	return (*a - *b);
}
