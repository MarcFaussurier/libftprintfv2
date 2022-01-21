#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
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
# define b10 "0123456789"
# define b8 "01234567x"
# define b16 "0123456789abcdefx"
# define B16 "0123456789ABCDEFX"
# define _ ""
# define block __block
# define auto __auto_type
/*
 *****************
 *	ft_*.c 
 *****************
 */
typedef int (*t_print_char)(char c);
int 			ft_vcprintf(t_print_char p, void *d, const char *f,va_list a);
int 			ft_cprintf(t_print_char print, void *data, const char *format, ...);
int				ft_vsnprintf(char *  str, size_t size, const char *  format, va_list ap);
int				ft_vsprintf(char *  str, const char *  format, va_list ap);
int				ft_vdprintf(int fd, const char *  format, va_list ap);
int				ft_vprintf(const char *  format, va_list ap);
int				ft_vasprintf(char **ret, const char *format, va_list ap);
int				ft_snprintf(char *str, size_t size, const char *  format, ...);
int				ft_sprintf(char *str, const char *  format, ...);
int				ft_dprintf(int fd, const char *  format, ...);
int				ft_printf(const char *  format, ...);
int				ft_asprintf(char **ret, const char *format, ...);
/*
 *****************
 *	primitives.c 
 *****************
 */
int 			ft_print_str(t_print_char print, char *s);
int 			ft_print_ullong(t_print_char print, long long n, const char *b, int bl);
int 			ft_print_llong(t_print_char print, long long n, const char *b, int bl);
int				ft_print_ldbl_base(t_print_char print, long double d, const char *b, int bl);
/*
 *****************
 *	implementation.c 
 *****************
 */
typedef struct	s_printf
{
	struct 		s_flags
	{
		char				minus:	1;
		char				zero:	1;
    	char				dot:	1;
		char				sharp:  1;
		char				space:	1;
		char				plus:	1;
	}			flags;
	int			width;
	int			precision;
}				t_printf;
typedef	int 	(*t_printf_specifier)(t_print_char print, int i, va_list a);
short int		ft_printf_hash(char *s);
extern struct 
{
		char 				**s; 
		t_printf_spec	f;
} 				g_printf_hashmap[FT_PRINTF_HASHMAP_SIZE];
int 			ft_printf_register(char **s, t_printf_specifier f);
t_printf_specifier	
				ft_printf_parse(t_printf_context *c, const char **f, va_list a);
#endif
