#include <stdio.h>
#include "libftprintf.h"

static int	print(char c)
{
	write(1, &c, 1);
	return (1);
}

#if DYNAMIC_PRINTF == 0

static const
#endif 
char *g_av[] = {
	"hhi",
	"hi",
	"i",
	"li",
	"lli",
	//
	"hhd",
	"hd",
	"d",
	"ld",
	"lld",
	//
	"x",
	//
	"X",
	//
	"o",
	//
	"s",
	//
	"p",
	//
	"c",
	"c",
	//
	"f",
	//
	"g",
	//
	"a",
	//
	"n",
	//
	"b",
};

int	main(void)
{
	short int			ac;
	short int			hash;
	static const char	*passed[FT_PRINTF_HASHMAP_SIZE];

	ac = sizeof(g_av) / sizeof(const char *);
	while (--ac >= 0)
	{
		hash = ft_printf_hash(g_av[ac]);
		ft_cprintstr(print, g_av[ac]);
		ft_cprintstr(print, "\t");
		ft_cprintullong_base(print, B10, 10, hash);
		ft_cprintstr(print, "\n");
		if (passed[hash])
		{
			ft_cprintstr(print, "hash collision with \"");
			ft_cprintstr(print, passed[hash]);
			ft_cprintstr(print, "\" and \"");
			ft_cprintstr(print, g_av[ac]);
			ft_cprintstr(print, "\" [hash=");
			ft_cprintullong_base(print, B10, 10, hash);
			ft_cprintstr(print, "]\n");
		}
		passed[hash] = g_av[ac];
	}
	return (0);
}
