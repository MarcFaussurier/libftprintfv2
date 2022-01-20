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
# define LLONG_MIN_A "9223372036854775807"
# if LLONG_MIN != 9223372036854775807LL
#  error "edit header according your platform for LLONG_MIN LLONG_MIN_A"
# endif
# define b10 "0123456789"
# define b8 "01234567x"
# define b16 "0123456789abcdefx"
# define B16 "0123456789ABCDEFX"
# define _ ""
# define block __block
# define auto __auto_type
typedef void (*t_putchar)(int i, char c);
int 			ft_vcprintf(t_putchar putchar, void *data, const char *format, va_list ap);
int 			ft_cprintf(t_putchar putchar, void *data, const char *format, ...);
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
typedef struct	s_printf_ctx
{
	struct 		s_flags
	{
		char		minus:	1;
		char		zero:	1;
    	char		dot:	1;
		char		sharp:  1;
		char		space:	1;
		char		plus:	1;
	}			flags;
	int			width;
	int			precision;
}				t_printf_ctx;
typedef	int (*t_printf_specifier)(t_putchar p, int i, va_list a);
extern struct {char **, t_printf_ext} g_printf_hashmap[FT_PRINTF_HASHMAP_SIZE];
short int		ft_printf_hash(char *str);
int 			ft_printf_check_hashmap();
t_specifier 	ft_printf_find_ext(t_printf_ctx *ctx, char **format, int i, va_list ap);
int 			ft_putullong_base(t_putchar putchar, long long n, const char *b, int bl);
int 			ft_putllong_base(t_putchar putchar, long long n, const char *b, int bl);
#endif
