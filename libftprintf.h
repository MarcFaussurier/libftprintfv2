#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# ifndef PRINTF_BUFFER_SIZE
#  define PRINTF_BUFFER_SIZE 4096
# endif
# define _ -42
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
typedef struct	s_printf_ctx
{
	char		minus:	1;
	char		zero:	1;
    char		plus:	1;
	char		space:  1;
	char		sharp:	1;
	int			width;
	int			precision;
	char		c1;
	char		c2;
	char		c3;
}				t_printf_ctx;
typedef			int (*t_printf_fn)(t_printf_ctx *ctx, char *str, size_t size, va_list ap);
t_printf_fn		ft_printf_arg(t_printf_ctx *ctx, const char **format, va_list ap);
extern			t_printf_fn g_printf_ids[127 * 3];
short int		ft_printf_hash(char *str);
void			ft_printf_id_add(t_printf_fn callable, ...);
void			ft_printf_default();

#endif
