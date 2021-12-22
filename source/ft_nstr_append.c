#include "../libftprintf.h"

inline int 		ft_nstr_append(int *i, char **str, size_t *size, char c)
{
	int 		r;

	r = 0;
	if (*size)
	{
		*size -= 1;
		**str = c;
//		printf(" -- %c\n", c);
		*str += 1;
		r = 1;
	}
	*i += 1;
	return (r);
}
