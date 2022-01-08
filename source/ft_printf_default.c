#include "../libftprintf.h"

static void		ft_phase_a()
{
	ft_printf_id_add((void*)&ft_vsnprintf_sshrt, "hhd", "hhi",						_);
	ft_printf_id_add((void*)&ft_vsnprintf_shrt, "hd", "hi",							_);
	ft_printf_id_add((void*)&ft_vsnprintf_int, "d", "i",								_);
	ft_printf_id_add((void*)&ft_vsnprintf_long, "ld", "li",							_);
	ft_printf_id_add((void*)&ft_vsnprintf_llong, "Ld", "lld", "zd",
			"hhD", "hD", "D", "lD", "LD", "llD", "zD", _);
	ft_printf_id_add((void*)&ft_vsnprintf_usshrt, "hhu",								_);
	ft_printf_id_add((void*)&ft_vsnprintf_ushrt, "hu",								_);
	ft_printf_id_add((void*)&ft_vsnprintf_uint, "u",									_);
	ft_printf_id_add((void*)&ft_vsnprintf_ulong, "lu",								_);
	ft_printf_id_add((void*)&ft_vsnprintf_ullong, "Lu", "llu", "zu",					_);
	ft_printf_id_add((void*)&ft_vsnprintf_osshrt, "hho",								_);
	ft_printf_id_add((void*)&ft_vsnprintf_oshrt, "ho", 			_);
	ft_printf_id_add((void*)&ft_vsnprintf_oint, "o", 			_);
	ft_printf_id_add((void*)&ft_vsnprintf_olong, "lo", 			_);
	ft_printf_id_add((void*)&ft_vsnprintf_ollong, "Lo", "llo", "zo",
			"hhO", "hO", "O", "lO", "LO", "llO", "zO", 	_);
}

static void ft_phase_b()
{

	ft_printf_id_add((void*)&ft_vsnprintf_xsshrt, "hhx", 			_);
	ft_printf_id_add((void*)&ft_vsnprintf_xshrt, "hx", 			_);
	ft_printf_id_add((void*)&ft_vsnprintf_xint, "x",	 		_);
	ft_printf_id_add((void*)&ft_vsnprintf_xlong, "lx", 			_);
	ft_printf_id_add((void*)&ft_vsnprintf_xllong, "Lx", "llx", "zx", 	_);
	ft_printf_id_add((void*)&ft_vsnprintf_xsshrt_up, "hhX",		_);
	ft_printf_id_add((void*)&ft_vsnprintf_xshrt_up, "hX", 		_);
	ft_printf_id_add((void*)&ft_vsnprintf_xint_up, "X",	 		_);
	ft_printf_id_add((void*)&ft_vsnprintf_xlong_up, "lX", 		_);
	ft_printf_id_add((void*)&ft_vsnprintf_xllong_up, "llX", "zX", 	_);
}

static void		ft_phase_c()
{
	ft_printf_id_add((void*)&ft_vsnprintf_char, "hhc", "hc", "c", "lc", "llc", "zc", "Lc",
			"hhC", "hC", "C", "lC", "llC", "zC", "LC", _);
	ft_printf_id_add((void*)&ft_vsnprintf_str, "hhs", "hs", "s", "ls", "lls", "zs", "Ls",
			"hhS", "hS", "S", "lS", "llS", "zS", "LS", _);
	ft_printf_id_add((void*)&ft_vsnprintf_ptr, "hhp", "hp", "p", "lp", "llp", "zp", "Lp",
			_);
	ft_printf_id_add((void*)&ft_vsnprintf_cnt, "hhn", "hn", "n", "ln", "lln", "zn", "Ln",
			_);
	ft_printf_id_add((void*)&ft_vsnprintf_percent, "%", _);
	ft_printf_id_add((void*)&ft_vsnprintf_flt, "hhf", "hf", "f", 
			"llf", "zf", "hhF", "hF", "F",  
			"llF", "zF",					_);
	ft_printf_id_add((void*)&ft_vsnprintf_dbl, "lf", "lF", 		_);
	ft_printf_id_add((void*)&ft_vsnprintf_ldbl, "LF",	 	_);
}

static void		ft_phase_d()
{
	ft_printf_id_add((void*)&ft_vsnprintf_eflt, "hhe", "he", "e",
			"lle", "ze", 					_);
	ft_printf_id_add((void*)&ft_vsnprintf_edbl, "le", 			_);
	ft_printf_id_add((void*)&ft_vsnprintf_eldbl, "Le", 		 	_);
	ft_printf_id_add((void*)&ft_vsnprintf_eflt_up, "hhE", "hE", "E",
			"llE", "zE", 					_);
	ft_printf_id_add((void*)&ft_vsnprintf_edbl_up, "lE", 			_);
	ft_printf_id_add((void*)&ft_vsnprintf_eldbl_up, "LE", 		_);
	ft_printf_id_add((void*)&ft_vsnprintf_gflt, "hhg", "hg", "g", 
			"llg", "zg", 					_);
	ft_printf_id_add((void*)&ft_vsnprintf_gdbl, "lg", 			_);
	ft_printf_id_add((void*)&ft_vsnprintf_gldbl, "Lg", 		 	_);
	ft_printf_id_add((void*)&ft_vsnprintf_gflt_up, "hhG", "hG", "G",
			"llG", "zG", 					_);
	ft_printf_id_add((void*)&ft_vsnprintf_gdbl_up, "lG", 			_);
	ft_printf_id_add((void*)&ft_vsnprintf_gldbl_up, "LG", 		_);
	ft_printf_id_add((void*)&ft_vsnprintf_aflt, "hha", "ha", "a",
			"lla", "za", 					_);
	ft_printf_id_add((void*)&ft_vsnprintf_adbl, "la", 			_);
	ft_printf_id_add((void*)&ft_vsnprintf_aldbl, "La", 		 	_);
	ft_printf_id_add((void*)&ft_vsnprintf_aflt_up, "hhA", "hA", "A", 
			"llA", "zA", 					_);
	ft_printf_id_add((void*)&ft_vsnprintf_adbl_up, "lA", 			_);
	ft_printf_id_add((void*)(void*)&ft_vsnprintf_aldbl_up, "LA", 		_);
}

void	ft_printf_default()
{
	ft_phase_a();
	ft_phase_b();
	ft_phase_c();
	ft_phase_d();
}
