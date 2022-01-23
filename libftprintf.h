#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# define DYNAMIC_PRINTF 0
# define FT_PRINTF_HASHMAP_SIZE 1016
# define FT_PRINTF_LABEL_SIZE 11
# define FT_ASPRINTF_BUFFER_MIN 128
# define FT_PRINTF_BUFFER_SIZE 4096
# define FT_PRINTF_HASHMAP_SYNONYMES 5
# define LLONG_MIN_A "-9223372036854775808"
# define B10 "0123456789"
# define B8 "01234567x"
# define B16 "0123456789abcdefx"
# define B16C "0123456789ABCDEFX"
# define T
/*
 *****************
 *	ft_cprint.c 
 *****************
 */
typedef int		(^t_printchar)(char c);
int				ft_cprintstr(t_printchar print, const char *s);
int				ft_cprintullong_base(t_printchar print, const char *b, int bl,
					unsigned long long n);
int				ft_cprintllong_base(t_printchar print, const char *b, int bl,
					long long n);
int				ft_cprintldbl_base(t_printchar print, const char *b, int bl,
					long double d);
/*
 *****************
 *	ft_cprintf.c 
 *****************
 */
int				ft_vcprintf(t_printchar print, const char *format, va_list ap);
typedef struct s_printf_context
{
	struct				s_flags
	{
		char				minus:	1;
		char				zero:	1;
		char				dot:	1;
		char				sharp:	1;
		char				space:	1;
		char				plus:	1;
	}					flags;
	int					width;
	int					precision;
}				t_printf_context;
typedef	int		(^t_printf_specifier)(t_printf_context ctx, t_printchar print,
					int i, va_list a);
short int		ft_printf_hash(const char *s);
typedef struct s_printf_hashmap
{
	char				*s[FT_PRINTF_HASHMAP_SYNONYMES];
	t_printf_specifier	f;
}						t_printf_hashmap[FT_PRINTF_HASHMAP_SIZE];
# if DYNAMIC_PRINTF == 1

extern
t_printf_hashmap g_printf_hashmap;
# endif
/*
 *****************
 *	ft_vprintf.c 
 *****************
 */
int				ft_vsnprintf(char *str, size_t size, const char *format,
					va_list ap);
int				ft_vsprintf(char *str, const char *format, va_list ap);
int				ft_vdprintf(int fd, const char *format, va_list ap);
int				ft_vprintf(const char *format, va_list ap);
int				ft_vasprintf(char **ret, const char *format, va_list ap);
/*
 *****************
 *	ft_printf.c 
 *****************
 */
int				ft_snprintf(char *str, size_t size, const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_printf(const char *format, ...);
int				ft_asprintf(char **ret, const char *format, ...);

/*
 *****************
 *	ft_strcmp.c
 *****************
 */
int				ft_strcmp(char *a, char *b);
#endif
