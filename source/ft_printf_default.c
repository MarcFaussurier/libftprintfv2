#include "libftprintf.h"

static void		ft_phase_a()
{
	ft_printf_id_add(&ft_printf_sshrt, "hhd", "hhi",						_);
	ft_printf_id_add(&ft_printf_shrt, "hd", "hi",							_);
	ft_printf_id_add(&ft_printf_int, "d", "i",								_);
	ft_printf_id_add(&ft_printf_long, "ld", "li",							_);
	ft_printf_id_add(&ft_printf_llong, "Ld", "lld", "zd",
			"hhD", "hD", "D", "lD", "LD", "llD", "zD", 	_);
	ft_printf_id_add(&ft_printf_usshrt, "hhu",								_);
	ft_printf_id_add(&ft_printf_ushrt, "hu",								_);
	ft_printf_id_add(&ft_printf_uint, "u",									_);
	ft_printf_id_add(&ft_printf_ulong, "lu",								_);
	ft_printf_id_add(&ft_printf_ullong, "Lu", "llu", "zu",					_);
	ft_printf_id_add(&ft_printf_osshrt, "hho",								_);
	ft_printf_id_add(&ft_printf_oshrt, "ho", 			_);
	ft_printf_id_add(&ft_printf_oint, "o", 			_);
	ft_printf_id_add(&ft_printf_olong, "lo", 			_);
	ft_printf_id_add(&ft_printf_ollong, "Lo", "llo", "zo",
			"hhO", "hO", "O", "lO", "LO", "llO", "zO", 	_);
}

static void ft_phase_b()
{

	ft_printf_id_add(&ft_printf_xsshrt, "hhx", 			_);
	ft_printf_id_add(&ft_printf_xshrt, "hx", 			_);
	ft_printf_id_add(&ft_printf_xint, "x",	 		_);
	ft_printf_id_add(&ft_printf_xlong, "lx", 			_);
	ft_printf_id_add(&ft_printf_xllong, "Lx", "llx", "zx", 	_);
	ft_printf_id_add(&ft_printf_xsshrt_up, "hhX",		_);
	ft_printf_id_add(&ft_printf_xshrt_up, "hX", 		_);
	ft_printf_id_add(&ft_printf_xint_up, "X",	 		_);
	ft_printf_id_add(&ft_printf_xlong_up, "lX", 		_);
	ft_printf_id_add(&ft_printf_xllong_up, "lX", "llX", "zX", 	_);
}

static void		ft_phase_c()
{
	ft_printf_id_add(&ft_printf_char, "hhc", "hc", "c", "lc", "llc", "zc", "Lc",
			"hhC", "hC", "C", "lC", "llC", "zC", "LC", _);
	ft_printf_id_add(&ft_printf_str, "hhs", "hs", "s", "ls", "lls", "zs", "Ls",
			"hhS", "hS", "S", "lS", "llS", "zS", "LS", _);
	ft_printf_id_add(&ft_printf_ptr, "hhp", "hp", "p", "lp", "llp", "zp", "Lp",
			_);
	ft_printf_id_add(&ft_printf_cnt, "hhn", "hn", "n", "ln", "lln", "zn", "Ln",
			_);
	ft_printf_id_add(&ft_printf_percent, "%", _);
	ft_printf_id_add(&ft_printf_flt, "hhf", "hf", "f", "lf",
			"llf", "zf", "hhF", "hF", "F", "lF", 
			"llF", "zF"					_);
	ft_printf_id_add(&ft_printf_dbl, "lf", "lF" 		_);
	ft_printf_id_add(&ft_printf_ldbl, "Lf", "LF"	 	_);
}

static void		ft_phase_d()
{
	ft_printf_id_add(&ft_printf_eflt, "hhe", "he", "e", "le",
			"lle", "ze", 					_);
	ft_printf_id_add(&ft_printf_edbl, "le", 			_);
	ft_printf_id_add(&ft_printf_eldbl, "Le", 		 	_);
	ft_printf_id_add(&ft_printf_eflt_up, "hhE", "hE", "E", "lE",
			"llE", "zE", 					_);
	ft_printf_id_add(&ft_printf_edbl_up, "lE", 			_);
	ft_printf_id_add(&ft_printf_eldbl_up, "LE", 		_);
	ft_printf_id_add(&ft_printf_gflt, "hhg", "hg", "g", "lg",
			"llg", "zg", 					_);
	ft_printf_id_add(&ft_printf_gdbl, "lg", 			_);
	ft_printf_id_add(&ft_printf_gldbl, "Lg", 		 	_);
	ft_printf_id_add(&ft_printf_gflt_up, "hhG", "hG", "G", "lG",
			"llG", "zG", 					_);
	ft_printf_id_add(&ft_printf_gdbl_up, "lG", 			_);
	ft_printf_id_add(&ft_printf_gldbl_up, "LG", 		_);
	ft_printf_id_add(&ft_printf_aflt, "hha", "ha", "a", "la",
			"lla", "za", 					_);
	ft_printf_id_add(&ft_printf_adbl, "la", 			_);
	ft_printf_id_add(&ft_printf_aldbl, "La", 		 	_);
	ft_printf_id_add(&ft_printf_aflt_up, "hhA", "hA", "A", "lA", 
			"llA", "zA", 					_);
	ft_printf_id_add(&ft_printf_adbl_up, "lA", 			_);
	ft_printf_id_add(&ft_printf_aldbl_up, "LA", 		_);
}

void	ft_printf_default()
{
	ft_phase_a();
	ft_phase_b();
	ft_phase_c();
	ft_phase_d();
}
