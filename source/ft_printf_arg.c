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
        return (127 * 8 - 42);
    while (str[i])
        hash = 31 * hash + str[i++];
    return (hash % (127 * 8));
}


void			ft_printf_id_add (t_printf_fn callable, ...)
{
	va_list		ap;
	char		*id;
	int	 	h;

	va_start (ap, callable);
	while (1)
	{
		id = va_arg (ap, char *);
		if (!id[0])
			break;
		h = ft_printf_hash (id);
		if (g_printf_ids[h])
		{
			printf("error: printf identifier [id=%s, h=%i]", id, h);
			printf(" already exists as %s, use a different label!\n", g_printf_labels[h]);
			g_i += 1;
		}
		else
		{
			g_printf_ids[ft_printf_hash(id)] = callable;
			g_printf_labels[ft_printf_hash(id)] = id;
		}
	}
	va_end(ap);
}

t_printf_fn		ft_printf_arg (t_printf_ctx *ctx, va_list ap)
{
	char		label[11];
	size_t		i;
	short int 	hash;

	*(ctx->format) += 1;
	i = 0;
	while ((*(ctx->format))[i])
	{
		label[i] = (*(ctx->format))[i];
		if (!**(ctx->format))
		{
			break ;
		}
		i += 1;
		label[i] = 0;
		hash = ft_printf_hash(label);
		if (g_printf_ids[hash])
		{
			*(ctx->format) += i;
			//printf("FOUND %%%s with %s\n", g_printf_labels[hash], label);
			return (g_printf_ids[hash]);
		}
	}
//	*(ctx->format) += i;
	label[i] = 0;
//	printf("NOT FOUND %%%s\n", label);
	return (&ft_vsnprintf_fmt);
}
