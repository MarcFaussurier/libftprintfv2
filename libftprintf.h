#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# include <stdio.h>

# ifndef PRINTF_BUFFER_SIZE
#  define PRINTF_BUFFER_SIZE 4096
# endif
# define b10 "0123456789"
# define b8 "01234567x"
# define b16 "0123456789abcdefx"
# define B16 "0123456789ABCDEFX"
# define _ ""
# define __ void
int				ft_printf(const char *  format, ...);
int				ft_sprintf(char *  str, const char *  format, ...);
int				ft_snprintf(char *  str, size_t size, const char *  format, ...);
int				ft_asprintf(char **ret, const char *format, ...);
int				ft_dprintf(int fd, const char *  format, ...);
int				ft_vprintf(const char *  format, va_list ap);
int				ft_vsprintf(char *  str, const char *  format, va_list ap);
int				ft_vsnprintf(char *  str, size_t size, const char *  format, va_list ap);
int				ft_vasprintf(char **ret, const char *format, va_list ap);
int				ft_vdprintf(int fd, const char *  format, va_list ap);
extern int g_i;
typedef struct	s_printf_ctx
{
	char		minus:	1;
	char		zero:	1;
    char		plus:	1;
	char		space:  1;
	char		sharp:	1;
	int			width;
	int			precision;
	char		label[8];
	const char 	**format;
}				t_printf_ctx;
typedef			int (t_printf_fnd);
typedef			t_printf_fnd *t_printf_fn;

t_printf_fnd 	ft_printf_arg(t_printf_ctx *ctx, va_list ap);
extern t_printf_fn g_printf_ids[127 * 8];
short int		ft_printf_hash(char *str);
void			ft_printf_id_add(t_printf_fn callable, ...);
void			ft_printf_default();
/**/
int 		ft_vsnprintf_fmt;
int		ft_nstr_append(int *i, char **str, size_t *size, char c);
/**/
int 			ft_snprintf_llong_base(t_printf_ctx *ctx, char **str, size_t *size, long long n, const char *b);
int 			ft_snprintf_ullong_base(t_printf_ctx *ctx, char **str, size_t *size, unsigned long long n, const char *b);

/**/
t_printf_fnd	ft_vsnprintf_sshrt;
t_printf_fnd 	ft_vsnprintf_shrt;
t_printf_fnd 	ft_vsnprintf_int;
t_printf_fnd 	ft_vsnprintf_long;
t_printf_fnd 	ft_vsnprintf_llong;
/**/
t_printf_fnd 	ft_vsnprintf_usshrt;
t_printf_fnd 	ft_vsnprintf_ushrt;
t_printf_fnd 	ft_vsnprintf_uint;
t_printf_fnd 	ft_vsnprintf_ulong;
t_printf_fnd 	ft_vsnprintf_ullong;
/**/
t_printf_fnd 	ft_vsnprintf_osshrt;
t_printf_fnd 	ft_vsnprintf_oshrt;
t_printf_fnd 	ft_vsnprintf_oint;
t_printf_fnd 	ft_vsnprintf_olong;
t_printf_fnd 	ft_vsnprintf_ollong;
/**/
t_printf_fnd 	ft_vsnprintf_xsshrt;
t_printf_fnd 	ft_vsnprintf_xshrt;
t_printf_fnd 	ft_vsnprintf_xint;
t_printf_fnd 	ft_vsnprintf_xlong;
t_printf_fnd 	ft_vsnprintf_xllong;
/**/
t_printf_fnd 	ft_vsnprintf_xsshrt_up;
t_printf_fnd 	ft_vsnprintf_xshrt_up;
t_printf_fnd 	ft_vsnprintf_xint_up;
t_printf_fnd 	ft_vsnprintf_xlong_up;
t_printf_fnd 	ft_vsnprintf_xllong_up;
/**/
t_printf_fnd 	ft_vsnprintf_flt;
t_printf_fnd 	ft_vsnprintf_dbl;
t_printf_fnd 	ft_vsnprintf_ldbl;
/**/
t_printf_fnd 	ft_vsnprintf_eflt;
t_printf_fnd 	ft_vsnprintf_edbl;
t_printf_fnd 	ft_vsnprintf_eldbl;
/**/
t_printf_fnd 	ft_vsnprintf_eflt_up;
t_printf_fnd 	ft_vsnprintf_edbl_up;
t_printf_fnd 	ft_vsnprintf_eldbl_up;
/**/
t_printf_fnd 	ft_vsnprintf_aflt;
t_printf_fnd 	ft_vsnprintf_adbl;
t_printf_fnd 	ft_vsnprintf_aldbl;
/**/
t_printf_fnd 	ft_vsnprintf_aflt_up;
t_printf_fnd 	ft_vsnprintf_adbl_up;
t_printf_fnd 	ft_vsnprintf_aldbl_up;
/**/
t_printf_fnd 	ft_vsnprintf_gflt;
t_printf_fnd 	ft_vsnprintf_gdbl;
t_printf_fnd 	ft_vsnprintf_gldbl;
/**/
t_printf_fnd 	ft_vsnprintf_gflt_up;
t_printf_fnd 	ft_vsnprintf_gdbl_up;
t_printf_fnd 	ft_vsnprintf_gldbl_up;
/**/
t_printf_fnd 	ft_vsnprintf_percent;
t_printf_fnd 	ft_vsnprintf_char;
t_printf_fnd 	ft_vsnprintf_ptr;
t_printf_fnd 	ft_vsnprintf_cnt;
t_printf_fnd 	ft_vsnprintf_str;

#endif
