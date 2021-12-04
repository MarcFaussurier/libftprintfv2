#include "../libftprintf.h"
#include "stdio.h"

t_printf_fn	g_printf_ids[127 * 3];

short int 	ft_printf_hash(char *str)
{
	i = 0;
	while (*str)
	{
		i += *str;
		str += 1;
	}
	return (i);
}

void		ft_printf_id_add(t_printf_fn *callable, ...)
{
	va_list		ap;
	char		*id;
	int	 	h;

	va_start(ap, callable);
	while (1)
	{
		id = va_arg(ap, char *);
		if (!id)
			break;
		h = ft_printf_hash(id);
		if (g_printf_ids[h])
		{
			printf("ft_printf: warning identifier \
					[id=%s, h=%s] already exists!\n",
					id, h);
		}
		g_printf_ids[ft_printf_hash(id)] = callable;
	}
	va_end(ap);
}

void 		ft_printf_ids_default()
{
	g_printf_ids[0] = 1;
	ft_printf_id_add(&ft_printf_sshrt, "hhd", "hhi", 		_);
	ft_printf_id_add(&ft_printf_shrt, "hd", "hi", 		_);
	ft_printf_id_add(&ft_printf_int, "d", "i", 			_);
	ft_printf_id_add(&ft_printf_long, "ld", "li", 		_);
	ft_printf_id_add(&ft_printf_llong, "Ld", "lld", "zd", 	_);
//			
	ft_printf_id_add(&ft_printf_usshrt, "hhu", 			_);
	ft_printf_id_add(&ft_printf_ushrt, "hu", 			_);
	ft_printf_id_add(&ft_printf_uint, "u", 			_);
	ft_printf_id_add(&ft_printf_ulong, "lu", 			_);
	ft_printf_id_add(&ft_printf_ullong, "Lu", "llu", "zu", 	_);

//
	ft_printf_id_add(&ft_printf_osshrt, "hho", 			_);
	ft_printf_id_add(&ft_printf_oshrt, "ho", 			_);
	ft_printf_id_add(&ft_printf_oint, "o", 			_);
	ft_printf_id_add(&ft_printf_olong, "lo", 			_);
	ft_printf_id_add(&ft_printf_ollong, "Lo", "llo", "zo", 
			"hhO", "hO", "O", "lO", "LO", "llO", "zO", 	_);

//
	ft_printf_id_add(&ft_printf_xsshrt, "hhx", 			_);
	ft_printf_id_add(&ft_printf_xshrt, "hx", 			_);
	ft_printf_id_add(&ft_printf_xint, "x",	 		_);
	ft_printf_id_add(&ft_printf_xlong, "lx", 			_);
	ft_printf_id_add(&ft_printf_xllong, "Lx", "llx", "zx", 	_);
//
	ft_printf_id_add(&ft_printf_xsshrt_up, "hhX",		_);
	ft_printf_id_add(&ft_printf_xshrt_up, "hX", 		_);
	ft_printf_id_add(&ft_printf_xint_up, "X",	 		_);
	ft_printf_id_add(&ft_printf_xlong_up, "lX", 		_);
	ft_printf_id_add(&ft_printf_xllong_up, "lX", "llX", "zX", 	_);
//
	
	ft_printf_id_add(&ft_printf_flt, "hhf", "hf", "f", "lf", 
			"llf", "zf", "hhF", "hF", "F", "lF", 
			"llF", "zF"					_);
	ft_printf_id_add(&ft_printf_dbl, "lf", "lF" 		_);
	ft_printf_id_add(&ft_printf_ldbl, "Lf", "LF"	 	_);

//
	ft_printf_id_add(&ft_printf_eflt, "hhe", "he", "e", "le", 
			"lle", "ze", 					_);
	ft_printf_id_add(&ft_printf_edbl, "le", 			_);
	ft_printf_id_add(&ft_printf_eldbl, "Le", 		 	_);
//
	ft_printf_id_add(&ft_printf_eflt_up, "hhE", "hE", "E", "lE", 
			"llE", "zE", 					_);
	ft_printf_id_add(&ft_printf_edbl_up, "lE", 			_);
	ft_printf_id_add(&ft_printf_eldbl_up, "LE", 		_);

//
	ft_printf_id_add(&ft_printf_gflt, "hhg", "hg", "g", "lg", 
			"llg", "zg", 					_);
	ft_printf_id_add(&ft_printf_gdbl, "lg", 			_);
	ft_printf_id_add(&ft_printf_gldbl, "Lg", 		 	_);
//
	ft_printf_id_add(&ft_printf_gflt_up, "hhG", "hG", "G", "lG", 
			"llG", "zG", 					_);
	ft_printf_id_add(&ft_printf_gdbl_up, "lG", 			_);
	ft_printf_id_add(&ft_printf_gldbl_up, "LG", 		_);


	ft_printf_id_add(&ft_printf_aflt, "hha", "ha", "a", "la", 
			"lla", "za", 					_);
	ft_printf_id_add(&ft_printf_adbl, "la", 			_);
	ft_printf_id_add(&ft_printf_aldbl, "La", 		 	_);
//
	ft_printf_id_add(&ft_printf_aflt_up, "hhA", "hA", "A", "lA", 
			"llA", "zA", 					_);
	ft_printf_id_add(&ft_printf_adbl_up, "lA", 			_);
	ft_printf_id_add(&ft_printf_aldbl_up, "LA", 		_);
//

	ft_printf_id_add(&ft_printf_char, "hhc", "hc", "c", "lc",
			"llc", "zc", "Lc"
			"hhC", "hC", "C", "lC",
			"llC", "zC", "LC", 				_);

	ft_printf_id_add(&ft_printf_str, "hhs", "hs", "s", "ls",
			"lls", "zs", "Ls"
			"hhS", "hS", "S", "lS",
			"llS", "zS", "LS", 				_);

	ft_printf_id_add(&ft_printf_ptr, "hhp", "hp", "p", "lp",
			"llp", "zp", "Lp",				_);

	ft_printf_id_add(&ft_printf_cnt, "hhn", "hn", "n", "ln",
			"lln", "zn", "Ln",				_);

	ft_printf_id_add(&ft_printf_percent, "%",			_);
	

}

t_print_fn		ft_printf_arg(t_printf_ctx *ctx, const char **format, va_list ap)
{
	int 		i;
	i = 0;
	if (!*(*format) != '%')
	{
		ctx->format_c = *(*format++);
	}
	else
	{
		ctx->format_c = 0;


		ctx->minus = 0;
	}

	return (i);
}
