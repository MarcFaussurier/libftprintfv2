#include "../libftprintf.h"
#include "stdio.h"

t_printf_fn		g_printf_ids[127 * 8];

char*			g_printf_labels[127 * 8];

int 			g_i = 0;

short int 		ft_printf_hash (char *str)
{
    unsigned 	hash;
	unsigned 	i;

	hash = 0;
	i = 0;

	if (str[0] == 'l' && str[1] == 'g')
	{
		return (127 * 8 - 42);
	}
    while (str[i])
        hash = 31 * hash + str[i++];
    return hash % (127 * 8);
}


void			ft_printf_id_add(t_printf_fn callable, ...)
{
	va_list		ap;
	char		*id;
	int	 	h;

	va_start(ap, callable);
	while (1)
	{
		id = va_arg(ap, char *);
		if (!id[0])
			break;
		h = ft_printf_hash(id);
		if (g_printf_ids[h])
		{
			printf("warning: printf identifier [id=%s, h=%i] already exists as %s! You should edit %i\n",
					id, h, g_printf_labels[h]);
			g_i += 1;
		}
		g_printf_ids[ft_printf_hash(id)] = callable;
		g_printf_labels[ft_printf_hash(id)] = id;
	}
	va_end(ap);
}

t_printf_fn		ft_printf_arg(t_printf_ctx *ctx, const char **format, va_list ap)
{


	return (0);
}
