#ifndef PRINT_H
# define PRINT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# define b10 "0123456789"
# define b8 "01234567x"
# define b16 "0123456789abcdefx"
# define B16 "0123456789ABCDEFX"
# define block __block
# ifndef DYNAMIC_PRINTF
#  define DYNAMIC_PRINTF 0
# endif
# ifndef FT_PRINTF_HASHMAP_SIZE 
#  define FT_PRINTF_HASHMAP_SIZE 127 * 8
# endif
# ifndef FT_PRINTF_LABEL_SIZE
#  define FT_PRINTF_LABEL_SIZE 11
# endif
# ifndef FT_ASPRINTF_BUFFER_MIN 
#  define FT_ASPRINTF_BUFFER_MIN 128
# endif
# ifndef FT_PRINTF_BUFFER_SIZE
#  define FT_PRINTF_BUFFER_SIZE 4096
# endif
# define LLONG_MIN_2 -9223372036854775807
# if LLONG_MAX != LLONG_MIN_2
# 	define LLONG_MIN_A "-9223372036854775807"
# else
#  error "edit header according your platform for LLONG_MIN LLONG_MIN_A"
# endif

/*
 *****************
 *	ft_cprint.c 
 *****************
 */
typedef int (*t_printchar)(char c);
int 			ft_cprintstr(t_printchar print, const char *s);
int 			ft_cprintullong_base(t_printchar print, const char *b, int bl, 
		unsigned long long n);
int 			ft_cprintllong_base(t_printchar print, const char *b, int bl, 
		long long n);
int				ft_cprintldbl_base(t_printchar print,  const char *b, int bl, 
		long double d);
/*
 *****************
 *	ft_cprintf.c 
 *****************
 */
int 			ft_vcprintf(t_printchar print, const char *format, va_list ap);
typedef struct	s_printf_context
{
	struct 				s_flags
	{
		char				minus:	1;
		char				zero:	1;
		char				dot:	1;
		char				sharp:  1;
		char				space:	1;
		char				plus:	1;
	}					flags;
	int					width;
	int					precision;
}				t_printf_context;
typedef	int 	(^t_printf_specifier)(t_printf_context ctx, t_printchar print, 
		int i, va_list a);
short int		ft_printf_hash(const char *s);
typedef struct	s_printf_hashmap
{
	char 				*s[5]; 
	t_printf_specifier	f;
}				t_printf_hashmap[FT_PRINTF_HASHMAP_SIZE];
extern t_printf_hashmap
				g_printf_hashmap;
/*
 *****************
 *	ft_vprintf.c 
 *****************
 */
int				ft_vsnprintf(char *  str, size_t size, const char *  format, va_list ap);
int				ft_vsprintf(char *  str, const char *  format, va_list ap);
int				ft_vdprintf(int fd, const char *  format, va_list ap);
int				ft_vprintf(const char *  format, va_list ap);
int				ft_vasprintf(char **ret, const char *format, va_list ap);
/*
 *****************
 *	ft_printf.c 
 *****************
 */
int				ft_snprintf(char *str, size_t size, const char *  format, ...);
int				ft_sprintf(char *str, const char *  format, ...);
int				ft_dprintf(int fd, const char *  format, ...);
int				ft_printf(const char *  format, ...);
int				ft_asprintf(char **ret, const char *format, ...);
#endif
