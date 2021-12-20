#include "../libftprintf.h"

void 		ft_nstr_append(int *i, char **str, size_t *size, char c)
{
	if (!c)
	{
		**str = c;
		return ;	
	}
	if (*size)
	{
		*size -= 1;
		**str = c;
		*str += 1;
	}
	*i += 1;
}
